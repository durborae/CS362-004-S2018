/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package unittest;
import java.util.regex.Pattern;
import java.util.Random;

/**
 *
 * @author Eric
 */
public class UnitTest {
    
    /*************************************************************
     * Unit it test for the isValidScheme Function
     *************************************************************/
    
    public void utIsValidScheme(){
        String[] DEFAULT_SCHEMES = {"http", "https", "ftp"};
        UrlValidator vu = new UrlValidator(DEFAULT_SCHEMES);
        
        System.out.println("Testing http, expected true");
        System.out.println(vu.isValidScheme("http"));
        System.out.println("Testing https, expected true");
        System.out.println(vu.isValidScheme("https"));
        System.out.println("Testing ftp, expected true");
        System.out.println(vu.isValidScheme("ftp"));
        System.out.println("Testing HTTP, expected true");
        System.out.println(vu.isValidScheme("HTTP"));
        System.out.println("Testing HTTPS, expected true");
        System.out.println(vu.isValidScheme("HTTPS"));
        System.out.println("Testing FTP, expected true");
        System.out.println(vu.isValidScheme("FTP"));
        System.out.println("Testing htp, expected false");
        System.out.println(vu.isValidScheme("htp"));
        System.out.println("Testing HTP, expected false");
        System.out.println(vu.isValidScheme("HTP"));
        System.out.println("Testing 23465, expected false");
        System.out.println(vu.isValidScheme("23465"));
    }
    /*
    public void utisValidAuthority(){
        String[] DEFAULT_SCHEMES = {"http", "https", "ftp"};
        UrlValidator vu = new UrlValidator(DEFAULT_SCHEMES);
        
         //Matcher urlMatcher = URL_PATTERN.matcher(value);
        
        System.out.println("Testing www.google.com, expect true");
        System.out.println(vu.isValidAuthority("www.google.com"));
        System.out.println("Testing www.GOOGLE.com, expect true");
        System.out.println(vu.isValidAuthority("www.GOOGLE.com"));
        System.out.println("Testing www.realestate.com, expect true");
        System.out.println(vu.isValidAuthority("www.realestate.com"));
        System.out.println("Testing www.google.net, expect true");
        System.out.println(vu.isValidAuthority("www.google.net"));
    }
    */
    
    /*************************************************************
     * Port Partition Test
     *************************************************************/
    
    public void port_partitioning_Test(){
        String[] DEFAULT_SCHEMES = {"http", "https", "ftp"};
        UrlValidator vu = new UrlValidator(DEFAULT_SCHEMES);
        System.out.println("testing port #80 expect true");
        System.out.println(vu.isValid("http://www.google.com:80"));
        System.out.println("testing port #65535 expect true");
        System.out.println(vu.isValid("http://www.google.com:65535"));
        System.out.println("testing port #65535 expect false");
        System.out.println(vu.isValid("http://www.google.com:65536"));
        System.out.println("testing port #-1 expect false");
        System.out.println(vu.isValid("http://www.google.com:-1"));
        System.out.println("testing port #65534 expect true");
        System.out.println(vu.isValid("http://www.google.com:65534"));
    }
    
    /*************************************************************
     * Domain Size Partition Test
     *************************************************************/
    
    public void domain_size_partitioning_test(){
        String[] DEFAULT_SCHEMES = {"http", "https", "ftp"};
        UrlValidator vu = new UrlValidator(DEFAULT_SCHEMES);
        String AB = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        int len = 248;//1 under max
        Random rnd = new Random();
        StringBuilder sb = new StringBuilder(len);
        StringBuilder url = new StringBuilder(256);
        url.append("http://");
        for(int x = 0; x < len; x++){
        sb.append(AB.charAt(rnd.nextInt(AB.length())));
        }
        sb.append(".com");
        url.append(sb);
        System.out.println("Testing " + url + " expect true");
        System.out.println(vu.isValid(url.toString()));
        
        url.delete(0, url.length());
        sb.delete(0, sb.length());
        len++;//equal
        
        url.append("http://");
        for(int x = 0; x < len; x++){
        sb.append(AB.charAt(rnd.nextInt(AB.length())));
        }
        sb.append(".com");
        url.append(sb);
        System.out.println("Testing " + url + " expect true");
        System.out.println(vu.isValid(url.toString()));
        
        url.delete(0, url.length());
        sb.delete(0, sb.length());
        len++;//one over
        
        url.append("http://");
        for(int x = 0; x < len; x++){
        sb.append(AB.charAt(rnd.nextInt(AB.length())));
        }
        sb.append(".com");
        url.append(sb);
        System.out.println("Testing " + url + " expect true");
        System.out.println(vu.isValid(url.toString()));
        
         url.delete(0, url.length());
        sb.delete(0, sb.length());
        len++;//one over
        
        url.append("http://");
        for(int x = 0; x < len; x++){
        sb.append(AB.charAt(rnd.nextInt(AB.length())));
        }
        sb.append(".com");
        url.append(sb);
        System.out.println("Testing " + url + " expect true");
        System.out.println(vu.isValid(url.toString()));
    }
    
    /*************************************************************
     * isValid Unit Test
     *************************************************************/
    
    public void isValidTest(){
        String[] DEFAULT_SCHEMES = {"http", "https", "ftp"};
        UrlValidator vu = new UrlValidator(DEFAULT_SCHEMES);
        System.out.println("Testing http://www.google.com expect true");
        System.out.println(vu.isValid("http://www.google.com"));
        System.out.println("Testing https://www.google.com expect true");
        System.out.println(vu.isValid("https://www.google.com"));
        System.out.println("Testing http://www.realestate.com expect true");
        System.out.println(vu.isValid("http://www.realestate.com"));
        System.out.println("Testing http://www.reeeeealestate.com expect false");
        System.out.println(vu.isValid("http://www.asdfasdfasdf.com"));
        System.out.println("Testing http://www.microsoft.net expect true");
        System.out.println(vu.isValid("http://www.microsoft.net"));
    }
    
    /**
     * Main Method
     */
    public static void main(String[] args) {
        UnitTest ut = new UnitTest();
        ut.utIsValidScheme();  
        ut.isValidTest();
        ut.utisValidAuthority();
        ut.port_partitioning_Test();
        ut.domain_size_partitioning_test();
    }
    
}
