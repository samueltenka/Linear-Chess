#include "ChessPosition.h"
#include <cstdlib>


inline bool Square::empty_on(ChessPosition& CP)
{
	return CP.piece_at((*this)) == NULL;
}
inline bool Square::on_board()
{
	return	(0 <= rank) && (rank < SIDELENGTH) && 
			(0 <= file) && (file < SIDELENGTH);
}
inline bool Piece::can_arrive_at(Square destination, ChessPosition& CP, bool takingOK, bool taking_required)
	// "inline" hints the compiler to expression-optimize taking-conditions hardcoded in "possible_moves"
{
	return	destination.on_board() &&
			(	(!taking_required && destination.empty_on(CP)) ||
				(!destination.empty_on(CP) && takingOK && CP.piece_at(destination)->color != color));
}

LinkedList<Square> ChessPosition::ray_from(Square source, int y_inc, int x_inc,
								int max_length, Piece piece, bool takingOK, bool taking_required)
{
	LinkedList<Square> ray;
	int count = 0;
	goto __start; // since don't want to append original square.
	do
	{
		ray.append(source);
		count++;
	__start:
		source.rank += y_inc;
		source.file += x_inc;
	} while(count < max_length &&
			piece.can_arrive_at(source, (*this), takingOK, taking_required));

	return ray;
}

LinkedList<Square> ChessPosition::possible_destinations(Square source, Piece piece)	// uses both piece.species (for move-generating algorithm)
{																					// and piece.color (for block/take conditions)
	LinkedList<Square> rtrn;

	int mobility = 100; // (max length of rays) == 100 for B, R, Q; == 1 for king.
	bool diagonals = true;
	bool orthogonals = true;
	int rank_inc, first_rank; // for pawn case

	switch(piece.species)
	{
		//
		// Pawn moves: we don't handle promotion here, just the motions.
	case pawn:
		rank_inc = (piece.color==black) ? +1 : -1;
		first_rank = (piece.color==black) ? 1 : 6;
		rtrn.append(ray_from(	source, rank_inc, 0, (source.rank==first_rank)?2:1,	// possible special "double-squared pawn advance"
								piece, false, false));								// taking is prohibited
		rtrn.append(ray_from(source, rank_inc,-1, 1, piece, true, true)); // taking is mandatory
		rtrn.append(ray_from(source, rank_inc,+1, 1, piece, true, true)); // taking is mandatory
		break;

		//
		// Knight moves:
	case knight:
		for(int y = -2; y <= +2; y++)
			for(int x = -2; x <= +2; x++)
				if(y*y + x*x == 2*2 + 1*1) // (2, 1)'s the only way to get 5, mod knight's choices.
				{
					Square square(source); square.rank += y; square.file += x;
					if(piece.can_arrive_at(square, (*this), true, false)) // taking is optional
						rtrn.append(square);
				}
		break;

		//
		// Cases easily treatable by rays:
	case king:
		mobility = 1;
	case queen:
	case rook:
		if(piece.species == rook)
			diagonals = false;
	case bishop:
		if(piece.species == bishop)
			orthogonals = false;

		for(int y = -1; y <= 1; y++)
			for(int x = -1; x <= 1; x++)
			{
				if(x==0 && y==0) continue;

				if(	(diagonals && ((x+y)%2==0)) ||
					(orthogonals && ((x+y)%2==1)))
				{
					rtrn.append(ray_from(source, y, x, mobility, piece, true, false)); // taking is optional
				}
			}
	}

	return rtrn;
}



LinkedList<Move> ChessPosition::possible_moves()	// copies previously computed destinations into move-tuples.
{													// perhaps TODO?!: let previous computations __return__ move-tuples to begin with,
													// so no explicit copying needed (though "append" copies behind the scenes)
	LinkedList<Move> rtrn;

	for(int i = 0; i < NUM_SQUARES; i++)
	{
		Square source(i);
		if(!source.empty_on(*this))
		{
			LinkedList<Square> destis = possible_destinations(source, *(this->piece_at(source)));
			for(LLIterator<Square> iter(destis); iter.can_continue(); iter.next())
			{
				rtrn.append(Move(source, iter.value()));
			}
		}
	}

	return rtrn;
}


ChessVector ChessPosition::state()
{
	ChessVector rtrn;
	rtrn.zero();

	for(int i = 0; i < NUM_SQUARES; i++)
	{
		Square source(i);
		if(!source.empty_on(*this))
		{
			Piece piece = *(this->piece_at(source));
			Dimension S(source, piece);
			rtrn.component(S) = 1.0; // can't overflow since white can't move onto white

			LinkedList<Square> PDs = possible_destinations(source, piece);
			for(LLIterator<Square> d(PDs); d.can_continue(); d.next())
			{
				Dimension D(d.value(), piece); // still use source piece
				rtrn.component(D) += 0.2;
			}
		}
	}

	return rtrn;
}
