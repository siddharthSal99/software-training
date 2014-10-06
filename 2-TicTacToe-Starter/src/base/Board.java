package base;
import java.util.List;


public class Board {
	
	public Board() {
	}
	
	public void mark(int row, int col, char marking) throws MarkPlacementException {
	}
	
	public char getMarking(int row, int col) {
		return 0;
	}
	
	public boolean isSpotEmpty(int row, int col) {
		return false;
	}
	
	public void reset() {
	}
	
	public class MarkPlacementException extends Exception {
		public int Row;
		public int Col;
		public MarkPlacementException(int row, int col, String message) {
			super(message);
			Row = row;
			Col = col;
		}
	}
	
	public boolean isEndState() {
//		// Horizontal
//		if(data[0][0] != ' ' && data[0][0] == data[0][1] && data[0][0] == data[0][2]) {
//			winner = data[0][0];
//			return true;
//		}
//		if(data[1][0] != ' ' && data[1][0] == data[1][1] && data[1][0] == data[1][2]) {
//			winner = data[1][0];
//			return true;
//		}
//		if(data[2][0] != ' ' && data[2][0] == data[2][1] && data[2][0] == data[2][2]) {
//			winner = data[2][0];
//			return true;
//		}
//		// Vertical
//		if(data[0][0] != ' ' && data[0][0] == data[1][0] && data[0][0] == data[2][0]) {
//			winner = data[0][0];
//			return true;
//		}
//		if(data[0][1] != ' ' && data[0][1] == data[1][1] && data[0][1] == data[2][1]) {
//			winner = data[0][1];
//			return true;
//		}
//		if(data[0][2] != ' ' && data[0][2] == data[1][2] && data[0][2] == data[2][2]) {
//			winner = data[0][2];
//			return true;
//		}
//		// Diagonal
//		if(data[0][0] != ' ' && data[0][0] == data[1][1] && data[0][0] == data[2][2]) {
//			winner = data[0][0];
//			return true;
//		}
//		if(data[2][0] != ' ' && data[2][0] == data[1][1] && data[2][0] == data[0][2]) {
//			winner = data[2][0];
//			return true;
//		}
//		if(getEmptyCells().isEmpty()) {
//			winner = 'T'; // T for tie
//			return true;
//		}
//		// No winner
//		winner = ' ';
		return false;
	}
	
	public char getWinner() {
		return 0;
	}
	
	public List<Point> getEmptyCells() {
		return null;
	}
}
