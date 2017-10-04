package generation;

import static org.junit.Assert.*;
import org.junit.*;

import org.junit.Test;

import falstad.MazeController;
import falstad.MazeController.UserInput;

public class MazeFactoryTest {
	private MazeController control;
	
	@Before
	public void setUp(){
		control = new MazeController();
		control.init();
		MazeFactory factory = new MazeFactory();
		factory.order(control);
		factory.waitTillDelivered();
		
	}
	
	
	
	@Test
	public void assertBuildSuccess() {
		control.keyDown(UserInput.Start, 4);
		assertNotNull(control.getBuilder());
		System.out.println("This is a success");
	}
	
	
	
	@Test
	public void testSolutionExistsFromAllCells() {
		MazeConfiguration config = control.getMazeConfiguration();
		for( int row = 0; row < config.getHeight(); row++) {
			for( int col = 0; col < config.getWidth(); col++) {
				int dist = config.getDistanceToExit(row, col);
				int adjDist;
				int[] xOffsets = {-1,1,0,0};
				int[] yOffsets = {0,0,-1,1};
				boolean hasAdjacentClosertoSolution = false;
				for(int i = 0;i < 4; i++ ) {
					try {
				
					adjDist = config.getDistanceToExit(row + xOffsets[i], col + yOffsets[i]);
					
					if(dist - adjDist ==1) {
						hasAdjacentClosertoSolution = true;
						break;
					}
					}catch(ArrayIndexOutOfBoundsException e) {};
				}
				if(dist != 1 && !hasAdjacentClosertoSolution) {
					fail();
				}
				
			}
		}
	}

}
