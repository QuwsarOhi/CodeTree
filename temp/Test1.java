import java.util.*;


public class Test1 {
    static int ConvDecimal(String str, int base) {
        TreeMap<Character, Integer> Map = new TreeMap<Character, Integer>();
        int ret = 0;
        
        for(int i = 0; i < 5; ++i)      // Map values A, B, C, D, E
            Map.put((char)('A'+i), 10+i);
        
        for(int i = 0; i < str.length(); ++i) {
            char x = str.charAt(i);
            int v = Map.get(x) == null ? x-'0':Map.get(x);
            System.out.format("For %c found %d\n", x, v);
            
            if(i > 0)
                ret *= base;
            ret += v;
        }
        return ret;
    }
     
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        String ss = sc.nextLine();
        
        int ret = ConvDecimal(ss, 15);
        System.out.format("Found %d\n", ret);
    }
}
