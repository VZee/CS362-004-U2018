

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
        public String string1 = 'http://www.google.com:80/test1?action=view';
        public String string2 = 'ftp://go.au/test1/';
        public String string3 = '10.0.0.0/$23';
        public String string4 = 'h3t://255.255.255.255/t123?action=edit&mode=up';
   }

   
   public void testYourSecondPartition(){
        //You can use this function to implement your Second Partition testing	  
        // All invalid (except for query)
        public String string5 = 'http:256.256.256.256:-1/../';
        public String string6 = '://:65636/..';
        public String string7 = '3ht://.1.2.3.4:-1/../';
        public String string8 = 'http:/256.256.256.256:65a/test1//file';
   }

    
   public void testYourThirdPartition(){
        // Only scheme (and query) valid
        public String string9 = 'h3t://1.2.3.4.:65636/test1//file?action=edit&mode=up';
        public String string10 = '.1.2.3.4:65a/test1//file';
        public String string11 = 'ftp://:65a/..//file';
        public String string12 = 'http://.aaa:-1/..//file';
   }

   public void testYourFourthPartition(){
        // Only scheme invalid
        public String string13 = 'http:/go.com:0/test1/?action=view';
        public String string14 = '3ht://go.au/test1/';
        public String string15 = 'http:255.com/t123?action=edit&mode=up';
        public String string16 = '://255.255.255.255:65535?action=edit&mode=up';
   }

   public void testYourFifthPartition(){
        // Only authority (and query) valid
        public String string17 = 'http:go.au:65a/..//file/#';
        public String string18 = 'http/255.com:-1/..?action=view';
        public String string19 = '://255.255.255.255:65636/..//file';
        public String string20 = 'http:/0.0.0.0:65636/test1//file?action=edit&mode=up';
   }

   public void testYourSixthPartition(){
        // Only authority invalid
        public String string21 = 'go.1aa/t123?action=view';
        public String string22 = ':0/test1/?action=edit&mode=up';
        public String string23 = 'h3t://.aaa/test1/file';
        public String string24 = 'http://256.256.256.256/test1?action=view';
   }

   public void testYourSeventhPartition(){
        // Only port (and query) valid
        public String string25 = '://256.256.256.256:80/../';
        public String string26 = '3ht://go.1aa:65535/../';
        public String string27 = 'http:/..';
        public String string28 = '://256.256.256.256:0/test1//file';
   }

   public void testYourEigthPartition(){
        // Only port invalid
        public String string29 = 'http://www.google.com:-1/test1?action=view';
        public String string30 = 'ftp://0.0.0.0:65636/test1/file';
        public String string31 = 'go.com:-1?action=edit&mode=up';
        public String string32 = '255.255.255.255:65a/test1/?action=view';
   }

   public void testYourNinthPartition(){
        // Only path (and query) valid
        public String string33 = '://256.256.256.256:-1/$23';
        public String string34 = 'http/go.1aa/$23';
        public String string35 = '://1.2.3.4.5/t123?action=view';
        public String string36 = '3ht://256.256.256.256:65a/test1/';
   }

   public void testYourTenthPartition(){
        // Only path invalid
        public String string37 = 'http://www.google.com:80/#?action=view';
        public String string38 = 'h3t://:0/..//file;';
        public String string39 = '255.255.255.255/..';
        public String string40 = 'h3t://255.255.255.255:80/../?action=view';
   }
   ////////////////////////////////////////////////////////////////////////////////////////////////


   ////////////////////////////////////////////////////////////////////////////////////////////////
   // Program Based Testing
   public void testIsValid()
   {
	   //You can use this function for programming based testing

   }
   


}
