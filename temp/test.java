import java.util.*;
import java.io.*;


public class test {
    
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        
        int n = in.nextInt();
        in.nextLine();
        String str = in.nextLine();
        
        char[] s = str.toCharArray();
        
        for(int i = 1; i <= n; ++i) {
            if(n%i == 0) {
                for(int l = 0, r = i-1; l < r; ++l, --r) {
                    char t = s[l];
                    s[l] = s[r];
                    s[r] = t;
                }
            }
        }
        
        for(int i = 0; i < n; ++i)
            System.out.printf("%c", s[i]);
    }
}
