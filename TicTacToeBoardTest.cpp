/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"

class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(TicTacToeBoardTest, toggle_turn)
{
  TicTacToeBoard board;
  Piece actual = board.toggleTurn();
  ASSERT_EQ(actual, O);
}

TEST(TicTacToeBoardTest, toggle_turn_again)
{
  TicTacToeBoard board;
  board.toggleTurn();
  Piece actual = board.toggleTurn();
  ASSERT_EQ(actual, X);
}

TEST(TicTacToeBoardTest, place_invalid_row)
{
  TicTacToeBoard board;
  Piece actual = board.placePiece(4, 2);
  ASSERT_EQ(actual, Invalid);
}

TEST(TicTacToeBoardTest, place_invalid_column)
{
  TicTacToeBoard board;
  Piece actual = board.placePiece(2, -2);
  ASSERT_EQ(actual, Invalid);
}

TEST(TicTacToeBoardTest, is_x)
{
  TicTacToeBoard board;
  board.placePiece(1, 2);
  Piece actual = board.getPiece(1, 2);
  ASSERT_EQ(actual, X);
}

TEST(TicTacToeBoardTest, not_x)
{
  TicTacToeBoard board;
  board.placePiece(1, 2);
  board.placePiece(2, 2);
  Piece actual = board.getPiece(2, 2);
  ASSERT_NE(actual, X);
}

TEST(TicTacToeBoardTest, is_o)
{
  TicTacToeBoard board;
  board.placePiece(1, 2);
  board.placePiece(2, 2);
  Piece actual = board.getPiece(2, 2);
  ASSERT_EQ(actual, O);
}

TEST(TicTacToeBoardTest, not_o)
{
  TicTacToeBoard board;
  board.placePiece(1, 2);
  Piece actual = board.getPiece(1, 2);
  ASSERT_NE(actual, O);
}

TEST(TicTacToeBoardTest, is_blank)
{
  TicTacToeBoard board;
  Piece actual = board.getPiece(2, 2);
  ASSERT_EQ(actual, Blank);
}

TEST(TicTacToeBoardTest, is_invalid)
{
  TicTacToeBoard board;
  Piece actual = board.getPiece(-2, 2);
  ASSERT_EQ(actual, Invalid);
}

TEST(TicTacToeBoardTest, horizontal_win)
{
  TicTacToeBoard board;
  board.placePiece(1, 2);
  board.placePiece(2, 2);
  board.placePiece(1, 0);
  board.placePiece(0, 0);
  board.placePiece(1, 1);
  board.placePiece(2, 0);
  Piece actual = board.getWinner();
  ASSERT_EQ(actual, X);

}

TEST(TicTacToeBoardTest, vertical_win)
{
  TicTacToeBoard board;
  board.placePiece(1, 2);
  board.placePiece(2, 1);
  board.placePiece(1, 0);
  board.placePiece(0, 1);
  board.placePiece(2, 2);
  board.placePiece(1, 1);
  Piece actual = board.getWinner();
  ASSERT_EQ(actual, O);

}

TEST(TicTacToeBoardTest, diagonal_win)
{
  TicTacToeBoard board;
  board.placePiece(0, 0);
  board.placePiece(2, 1);
  board.placePiece(1, 1);
  board.placePiece(0, 1);
  board.placePiece(2, 2);
  Piece actual = board.getWinner();
  ASSERT_EQ(actual, X);

}

TEST(TicTacToeBoardTest, not_over)
{
  TicTacToeBoard board;
  board.placePiece(1, 2);
  board.placePiece(2, 1);
  board.placePiece(1, 0);
  Piece actual = board.getWinner();
  ASSERT_EQ(actual, Invalid);

}

TEST(TicTacToeBoardTest, no_winner)
{
  TicTacToeBoard board;
  board.placePiece(0, 0);
  board.placePiece(0, 1);
  board.placePiece(0, 2);
  board.placePiece(1, 0);
  board.placePiece(1, 2);
  board.placePiece(2, 2);
  board.placePiece(1, 1);
  board.placePiece(2, 0);
  board.placePiece(2, 1);
  Piece actual = board.getWinner();
  ASSERT_EQ(actual, Blank);

}
