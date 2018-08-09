

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
   public void testManualTest() {

        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
    
        // Expected: valid     Result: invalid
        System.out.println(urlVal.isValid("http://www.amazon.com:65535"));
    
        // Expected: valid     Result: invalid
        System.out.println(urlVal.isValid("http://www.amazon.com:6553"));
    
        // Expected: valid     Result: invalid
        System.out.println(urlVal.isValid("http://www.amazon.com:655"));
    
        // Expected: valid     Result: invalid
        System.out.println(urlVal.isValid("http://www.amazon.com:65"));
    
        // Expected: valid     Result: invalid
        System.out.println(urlVal.isValid("http://www.amazon.com:6"));
        
        // Expected: invalid     Result: invalid
        System.out.println(urlVal.isValid("http://www.amazon.com:"));
        
        //Expected: Valid 	Result: Valid
        System.out.println(urlVal.isValid("http://www.amazon.com"));
            
        //Expected: Invalid	Result: Invalid
        System.out.println(urlVal.isValid("http://https://www.amazon.com"));
            
        //Expected: Invalid	Result: Valid
        System.out.println(urlVal.isValid("http://www.ama/zon.com"));
        
        //Expected: Valid	Result: Valid
        System.out.println(urlVal.isValid("http://amazon.org"));
        
        //Expected: Invalid	Result: valid
        System.out.println(urlVal.isValid("http://www.a?mazon.com"));
           
        //Expected: Valid	Result: Valid
        System.out.println(urlVal.isValid("http://www.amazon.com"));
            
        //Expected: Invalid	Result: Valid
        System.out.println(urlVal.isValid("http://2.2.2.255"));
        
        //Expected: Invalid	Result: Valid
        System.out.println(urlVal.isValid("http://2.2.2.256"));
        
        //Expected: Invalid	Result: Valid
        System.out.println(urlVal.isValid("http://2.2.2.895"));
         
        //Expected: Valid	Result: Valid
        System.out.println(urlVal.isValid("http://www.amazon.com"));
        
        //Expected: Valid	Result: Valid
        System.out.println(urlVal.isValid("http://www.amazon.com?x=1"));
        
        //Expected: Valid	Result: Valid
        System.out.println(urlVal.isValid("http://www.amazon.com?x"));
        
        //Expected: Invalid	Result: Invalid
        System.out.println(urlVal.isValid("http://www.amazon.com?x\n"));
        
        //Expected: Valid	Result: Valid
        System.out.println(urlVal.isValid("http://www.amazon.com?x\0"));
    }      
   ////////////////////////////////////////////////////////////////////////////////////////////////


   ////////////////////////////////////////////////////////////////////////////////////////////////
   // Partition Testing 
   // List of the string that will be used for input partitioning testing
    // All valid schemes were tested once the first valid url failed
   public void testYourFirstPartition()
   {
	    String[] scheme = {"http", "https", "ftp", "", "h3t"};
        UrlValidator urlVal = new UrlValidator(scheme);
        assertTrue(urlVal.isValid("http://www.google.com:80/test1?action=view"));
   }

   public void testSecondScheme(){
        String[] scheme = {"http", "https", "ftp", "", "h3t"};
        UrlValidator urlVal = new UrlValidator(scheme);
        assertTrue(urlVal.isValid("ftp://go.au/test1/"));
   }

   public void testThirdScheme(){
        String[] scheme = {"http", "https", "ftp", "", "h3t"};
        UrlValidator urlVal = new UrlValidator(scheme);
        assertTrue(urlVal.isValid("10.0.0.0/$23"));
   }

   public void testFourthScheme(){
        String[] scheme = {"http", "https", "ftp", "", "h3t"};
        UrlValidator urlVal = new UrlValidator(scheme);
        assertTrue(urlVal.isValid("h3t://255.255.255.255/t123?action=edit&mode=up"));
   }

   public void testFifthScheme(){
        String[] scheme = {"http", "https", "ftp", "", "h3t"};
        UrlValidator urlVal = new UrlValidator(scheme);
        assertTrue(urlVal.isValid("www.google.com:80/test1?action=view"));
   }

   // Now test false schemes
   public void testFalseScheme(){
       // Partition to test each scheme with the same rest of the URL
       // Different schemes can be chosen by commenting out all other ones
       // Default is for top assert to be the one to be registered via Eclipse debugger
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
        // Different schemes can be chosen by commenting out all other ones
        // Default is for top assert to be the one to be registered via Eclipse debugger
	    String[] scheme = {"http", "https", "ftp", "", "h3t"};
        UrlValidator urlVal = new UrlValidator(scheme);
        assertFalse(urlVal.isValid("http:256.256.256.256:-1/../"));
        assertFalse(urlVal.isValid("://:65636/.."));
        assertFalse(urlVal.isValid("3ht://.1.2.3.4:-1/../"));
        assertFalse(urlVal.isValid("http:/256.256.256.256:65a/test1//file"));
   }
    
   public void testYourThirdPartition(){
        // Only scheme (and query) valid
        // Different schemes can be chosen by commenting out all other ones
        // Default is for top assert to be the one to be registered via Eclipse debugger
	    String[] scheme = {"http", "https", "ftp", "", "h3t"};
        UrlValidator urlVal = new UrlValidator(scheme);
        assertFalse(urlVal.isValid("h3t://1.2.3.4.:65636/test1//file?action=edit&mode=up"));
        assertFalse(urlVal.isValid(".1.2.3.4:65a/test1//file"));
        assertFalse(urlVal.isValid("ftp://:65a/..//file"));
        assertFalse(urlVal.isValid("http://.aaa:-1/..//file"));
   }

   public void testYourFourthPartition(){
        // Only scheme invalid
        // Different schemes can be chosen by commenting out all other ones
        // Default is for top assert to be the one to be registered via Eclipse debugger
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
        // Different schemes can be chosen by commenting out all other ones
        // Default is for top assert to be the one to be registered via Eclipse debugger
	    String[] scheme = {"http", "https", "ftp", "", "h3t"};
        UrlValidator urlVal = new UrlValidator(scheme);
        assertFalse(urlVal.isValid("http:go.au:65a/..//file/#"));
        assertFalse(urlVal.isValid("http/255.com:-1/..?action=view"));
        assertFalse(urlVal.isValid("://255.255.255.255:65636/..//file"));
        assertFalse(urlVal.isValid("http:/0.0.0.0:65636/test1//file?action=edit&mode=up"));
   }

   public void testYourSixthPartition(){
        // Only authority invalid
        // Different schemes can be chosen by commenting out all other ones
        // Default is for top assert to be the one to be registered via Eclipse debugger
	    String[] scheme = {"http", "https", "ftp", "", "h3t"};
        UrlValidator urlVal = new UrlValidator(scheme);
        assertFalse(urlVal.isValid("go.1aa/t123?action=view"));
        assertFalse(urlVal.isValid(":0/test1/?action=edit&mode=up"));
        assertFalse(urlVal.isValid("h3t://.aaa/test1/file"));
        assertFalse(urlVal.isValid("http://256.256.256.256/test1?action=view"));
   }

   public void testYourSeventhPartition(){
        // Only port (and query) valid
        // Different schemes can be chosen by commenting out all other ones
        // Default is for top assert to be the one to be registered via Eclipse debugger
	    String[] scheme = {"http", "https", "ftp", "", "h3t"};
        UrlValidator urlVal = new UrlValidator(scheme);
        assertFalse(urlVal.isValid("://256.256.256.256:80/../"));
        assertFalse(urlVal.isValid("3ht://go.1aa:65535/../"));
        assertFalse(urlVal.isValid("http:/.."));
        assertFalse(urlVal.isValid("://256.256.256.256:0/test1//file"));
   }

   public void testYourEigthPartition(){
        // Only port invalid
        // Different schemes can be chosen by commenting out all other ones
        // Default is for top assert to be the one to be registered via Eclipse debugger
	    String[] scheme = {"http", "https", "ftp", "", "h3t"};
        UrlValidator urlVal = new UrlValidator(scheme);
        assertFalse(urlVal.isValid("http://www.google.com:-1/test1?action=view"));
        assertFalse(urlVal.isValid("ftp://0.0.0.0:65636/test1/file"));
        assertFalse(urlVal.isValid("go.com:-1?action=edit&mode=up"));
        assertFalse(urlVal.isValid("255.255.255.255:65a/test1/?action=view"));
   }

   public void testYourNinthPartition(){
        // Only path (and query) valid
        // Different schemes can be chosen by commenting out all other ones
        // Default is for top assert to be the one to be registered via Eclipse debugger
	    String[] scheme = {"http", "https", "ftp", "", "h3t"};
        UrlValidator urlVal = new UrlValidator(scheme);
        assertFalse(urlVal.isValid("://256.256.256.256:-1/$23"));
        assertFalse(urlVal.isValid("http/go.1aa/$23"));
        assertFalse(urlVal.isValid("://1.2.3.4.5/t123?action=view"));
        assertFalse(urlVal.isValid("3ht://256.256.256.256:65a/test1/"));
   }

   public void testYourTenthPartition(){
        // Only path invalid
        // Different schemes can be chosen by commenting out all other ones
        // Default is for top assert to be the one to be registered via Eclipse debugger
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
    // UNIT TEST 1
    //for loop cycles through the array of Test cases of URL schemes
    public void testSchemeValidity() {
        for (Test rp : testURLScheme)
            assertEquals(
                    rp.url,
                    rp.expected,
                    new UrlValidator().isValid(rp.url));
    }

    // UNIT TEST 2
    // for loop cycles through the array of Test cases of Authority

    public void testAuthorityValidity() {
        for (Test rp : testAuthority)
            assertEquals(
                    rp.url,
                    rp.expected,
                    new UrlValidator().isValid(rp.url));
    }

    // Test Class for arrays    
    // testURLScheme and testAuthority

    static class Test {
        String url;
        boolean expected;
        
        Test(String url, boolean expected) {
            this.url = url;
            this.expected = expected;
        }
    }

    Test[] testURLScheme = {
        
        new Test("https://news.google.com", true),
        new Test("12345678://", false),
        new Test("extremelylongstringthatshouldnotwork://", false),
        new Test("(*&[*^://", false),
        new Test("32434123://", false),
        new Test("http:256.256.256.256:-1/../", false),
        new Test("http:/256.256.256.256:65a/test1//file\"", false),
        new Test("http://www.example.com/space%20here.html", true)
    };

    Test[] testAuthority = {
        
        new Test("192.168.1.1", true),
        new Test("http://300.55.32.257.00.98.00.98", false),
        new Test(":0/test1/?action=edit&mode=up", false),
        new Test("http://192.168.1", false),
        new Test("255.255.255.255", true),
        new Test("http://900.55.33.257", false),
        new Test("1.1.1.1", true),
        new Test("http://256.256.256.256/test1?action=view", false)
    };

}
