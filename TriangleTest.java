import static org.junit.Assert.*;

import org.junit.Test;


public class TriangleTest {

	@Test
	public void testIsTriangle1() {
		 Triangle t = new Triangle(3,3,3);
		 assertEquals(t.getType(t),"Regular");
}
	

     @Test
     public void testIsTriangle2() {
	     Triangle t = new Triangle(2,1,3);
	     assertEquals(t.getType(t),"Illegal");
} 
     @Test
     public void testIsTriangle3() {
	     Triangle t = new Triangle(-3,-3,-3);
	     assertEquals(t.getType(t),"Regular");
} 
     @Test
     public void testIsTriangle4() {
	     Triangle t = new Triangle(4,5,6);
	     assertEquals(t.getType(t),"Scalene");

} 
     @Test
     public void testIsTriangle5() {
	     Triangle t = new Triangle(5,6,6);
	     assertEquals(t.getType(t),"Isoceles");

} 
     @Test
     public void testIsTriangle6() {
	     Triangle t = new Triangle(1,5,8);
	     assertEquals(t.getType(t),"Illegal");

} 
     @Test
     public void testIsTriangle7() {
	     Triangle t = new Triangle(0,2,2);
	     assertEquals(t.getType(t),"Illegal");
     }  
     public void testIsTriangle8() {
	     Triangle t = new Triangle(-2,-2,2);
	     assertEquals(t.getType(t),"Illegal");
     }  
}
     
 
     

