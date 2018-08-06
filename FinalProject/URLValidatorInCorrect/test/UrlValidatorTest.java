

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!



public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   ////////////////////////////////////////////////////////////////////////////////////////////////
   // Manual Testing
   public void testManualTest()
   {
//You can use this function to implement your manual testing	 
	   
	   
   }
   ////////////////////////////////////////////////////////////////////////////////////////////////


   ////////////////////////////////////////////////////////////////////////////////////////////////
   // Partition Testing 
   
   public void testYourFirstPartition()
   {
	    // List of the string that will be used for input partitioning testing
        // All valid
        
	    String[] scheme = {"http", "https", "ftp", "", "h3t"};
        UrlValidator urlVal = new UrlValidator(scheme);
        assertTrue(urlVal.isValid("http://www.google.com:80/test1?action=view"));
        assertTrue(urlVal.isValid("ftp://go.au/test1/"));
        assertTrue(urlVal.isValid("10.0.0.0/$23"));
        assertTrue(urlVal.isValid("h3t://255.255.255.255/t123?action=edit&mode=up"));
        assertTrue(urlVal.isValid("www.google.com:80/test1?action=view"));
   }

   public void testFalseScheme(){
       // Partition to test each scheme with the same rest of the URL
        String[] scheme = {"http", "https", "ftp", "", "h3t"};
        UrlValidator urlVal = new UrlValidator(scheme);
        assertFalse(urlVal.isValid("3ht://255.com"));
        assertFalse(urlVal.isValid("http:/255.com"));
        assertFalse(urlVal.isValid("http:255.com"));
        assertFalse(urlVal.isValid("http/255.com"));
        assertFalse(urlVal.isValid("://255.com"));
   }
   
   public void testYourSecondPartition(){
        //You can use this function to implement your Second Partition testing	  
        // All invalid (except for query)
	    String[] scheme = {"http", "https", "ftp", "", "h3t"};
        UrlValidator urlVal = new UrlValidator(scheme);
        assertFalse(urlVal.isValid("http:256.256.256.256:-1/../"));
        assertFalse(urlVal.isValid("://:65636/.."));
        assertFalse(urlVal.isValid("3ht://.1.2.3.4:-1/../"));
        assertFalse(urlVal.isValid("http:/256.256.256.256:65a/test1//file"));
   }
    
   public void testYourThirdPartition(){
        // Only scheme (and query) valid
	    String[] scheme = {"http", "https", "ftp", "", "h3t"};
        UrlValidator urlVal = new UrlValidator(scheme);
        assertFalse(urlVal.isValid("h3t://1.2.3.4.:65636/test1//file?action=edit&mode=up"));
        assertFalse(urlVal.isValid(".1.2.3.4:65a/test1//file"));
        assertFalse(urlVal.isValid("ftp://:65a/..//file"));
        assertFalse(urlVal.isValid("http://.aaa:-1/..//file"));
   }

   public void testYourFourthPartition(){
        // Only scheme invalid
	    String[] scheme = {"http", "https", "ftp", "", "h3t"};
        UrlValidator urlVal = new UrlValidator(scheme);
        assertFalse(urlVal.isValid("http:/go.com:0/test1/?action=view"));
        assertFalse(urlVal.isValid("3ht://go.au/test1/"));
        assertFalse(urlVal.isValid("http/255.com/t123?action=edit&mode=up"));
        assertFalse(urlVal.isValid("http:255.com/t123?action=edit&mode=up"));
        assertFalse(urlVal.isValid("://255.255.255.255:65535?action=edit&mode=up"));
   }

   public void testYourFifthPartition(){
        // Only authority (and query) valid
	    String[] scheme = {"http", "https", "ftp", "", "h3t"};
        UrlValidator urlVal = new UrlValidator(scheme);
        assertFalse(urlVal.isValid("http:go.au:65a/..//file/#"));
        assertFalse(urlVal.isValid("http/255.com:-1/..?action=view"));
        assertFalse(urlVal.isValid("://255.255.255.255:65636/..//file"));
        assertFalse(urlVal.isValid("http:/0.0.0.0:65636/test1//file?action=edit&mode=up"));
   }

   public void testYourSixthPartition(){
        // Only authority invalid
	    String[] scheme = {"http", "https", "ftp", "", "h3t"};
        UrlValidator urlVal = new UrlValidator(scheme);
        assertFalse(urlVal.isValid("go.1aa/t123?action=view"));
        assertFalse(urlVal.isValid(":0/test1/?action=edit&mode=up"));
        assertFalse(urlVal.isValid("h3t://.aaa/test1/file"));
        assertFalse(urlVal.isValid("http://256.256.256.256/test1?action=view"));
   }

   public void testYourSeventhPartition(){
        // Only port (and query) valid
	    String[] scheme = {"http", "https", "ftp", "", "h3t"};
        UrlValidator urlVal = new UrlValidator(scheme);
        assertFalse(urlVal.isValid("://256.256.256.256:80/../"));
        assertFalse(urlVal.isValid("3ht://go.1aa:65535/../"));
        assertFalse(urlVal.isValid("http:/.."));
        assertFalse(urlVal.isValid("://256.256.256.256:0/test1//file"));
   }

   public void testYourEigthPartition(){
        // Only port invalid
	    String[] scheme = {"http", "https", "ftp", "", "h3t"};
        UrlValidator urlVal = new UrlValidator(scheme);
        assertFalse(urlVal.isValid("http://www.google.com:-1/test1?action=view"));
        assertFalse(urlVal.isValid("ftp://0.0.0.0:65636/test1/file"));
        assertFalse(urlVal.isValid("go.com:-1?action=edit&mode=up"));
        assertFalse(urlVal.isValid("255.255.255.255:65a/test1/?action=view"));
   }

   public void testYourNinthPartition(){
        // Only path (and query) valid
	    String[] scheme = {"http", "https", "ftp", "", "h3t"};
        UrlValidator urlVal = new UrlValidator(scheme);
        assertFalse(urlVal.isValid("://256.256.256.256:-1/$23"));
        assertFalse(urlVal.isValid("http/go.1aa/$23"));
        assertFalse(urlVal.isValid("://1.2.3.4.5/t123?action=view"));
        assertFalse(urlVal.isValid("3ht://256.256.256.256:65a/test1/"));
   }

   public void testYourTenthPartition(){
        // Only path invalid
	    String[] scheme = {"http", "https", "ftp", "", "h3t"};
        UrlValidator urlVal = new UrlValidator(scheme);
        assertFalse(urlVal.isValid("http://www.google.com:80/#?action=view"));
        assertFalse(urlVal.isValid("h3t://:0/..//file;"));
        assertFalse(urlVal.isValid("255.255.255.255/.."));
        assertFalse(urlVal.isValid("h3t://255.255.255.255:80/../?action=view"));
   }
   ////////////////////////////////////////////////////////////////////////////////////////////////


   ////////////////////////////////////////////////////////////////////////////////////////////////
   // Program Based Testing
   public void testIsValid1() {

}
