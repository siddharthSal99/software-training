package base;

public class Game {
	private Board board;
	private int moveCount;
	private char[] players = {'X', 'O'};
	
	public Game() {
		board = new Board();
		moveCount = 0;
	}
	
	public void reset() {
		board.reset();
	}
	
	public void makeMove(int row, int col) throws Board.MarkPlacementException {
		board.mark(row, col, players[moveCount%players.length]);
		moveCount++;
	}
	
	public char getCurrentPlayerMarking() {
		return players[moveCount%players.length];
	}
	
	public boolean hasWinner() {
		return board.isEndState();
	}
	
	public char getWinner() {
		return board.getWinner();
	}
	
	public Board getBoard() {
		return board;
	}
}
