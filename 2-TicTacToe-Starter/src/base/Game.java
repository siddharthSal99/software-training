package base;

public class Game {
	
	public Game() {
	}
	
	public void reset() {
	}
	
	public void makeMove(int row, int col) throws Board.MarkPlacementException {
	}
	
	public char getCurrentPlayerMarking() {
		return 0;
	}
	
	public boolean hasWinner() {
		return false;
	}
	
	public char getWinner() {
		return 0;
	}
	
	public Board getBoard() {
		return null;
	}
}
