package base;
import java.util.List;

import lejos.nxt.Button;
import lejos.nxt.Sound;


public class Main {

	Robot robot;
	Game game;
	MoveGenerator generator;
	CommLink comm;
	
	public Main(MoveGenerator gen) {
		robot = new Robot();
		game = new Game();
		generator = gen;
		comm = new CommLink();
	}
	
	public static void badSound() {
		Sound.twoBeeps();
	}
	
	public void humansTurn() {
		List<Point> emptyCells = game.getBoard().getEmptyCells();
		for(Point cell : emptyCells) {
			robot.moveToCell(cell.row, cell.col, Robot.MoveMode.Read);
			if(robot.isLightDark()) {
				try {
					game.makeMove(cell.row, cell.col);
				} catch (Exception e) {
					badSound();
					robot.moveToHome();
					System.exit(1);
				}
				Sound.playTone(392, 250);
				break;
			}
			Sound.playTone(216, 250);
		}
		comm.sendBoardState(game.getBoard());
	}
	
	public void robotsTurn() {
		Point move = generator.getMove(game.getBoard(), game.getCurrentPlayerMarking());
		try {
			game.makeMove(move.row, move.col);
		} catch (Exception e) {
			badSound();
			robot.moveToHome();
			System.exit(1);
		}
		robot.moveToCell(move.row, move.col, Robot.MoveMode.Write);
		comm.sendBoardState(game.getBoard());
	}
	
	public static void main(String[] args) {
		Main mainInstance = new Main(new RandomMoveGenerator());
		try {
			while(true) {
				if(Button.waitForAnyPress() == Button.ID_ESCAPE)
					break;
				mainInstance.humansTurn();
				if(mainInstance.game.hasWinner()) {
					Sound.beepSequence();
					break;
				}
				mainInstance.robotsTurn();
				if(mainInstance.game.hasWinner()) {
					Sound.beepSequenceUp();
					break;
				}
			}
			mainInstance.robot.moveToHome();
		} catch(Exception e) {
			badSound();
			mainInstance.robot.moveToHome();
			System.out.println(e.getClass().toString());
			Button.waitForAnyPress();
		}
		mainInstance.comm.close();
	}

}
