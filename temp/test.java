import java.util.*;
import java.io.*;


public class test {
    
    public static void main(String[] args) throws IOException {
        FastReader in = new FastReader();
        
        int n = in.nextInt();
        int k = in.nextInt();
        
        //in.nextLine();
        String str = new String(in.nextLine());
        char[] s = str.toCharArray();
        
        //Vector<Stack<Integer>> st = new Vector<Stack<Integer>>();
        Vector<Queue<Integer>> Q = new Vector<Queue<Integer>>();
        
        for(int i = 0; i < 26; ++i) Q.add(new LinkedList<Integer>());
        
        for(int i = 0; i < n; ++i) {
            int p = s[i] - 'a';
            //System.out.println(st.size() + " " + p);
            Q.get(p).offer(i);
        }
        
        for(int i = 0; i < k; ++i) {
            boolean found = false;
            for(char x = 0; x < 26; ++x) {
                if(!Q.get(x).isEmpty()) {
                    found = true;
                    s[Q.get(x).peek()] = '0';
                    Q.get(x).poll();
                    break;
                }
            }
            if(found == false)
                break;
        }
        
        for(int i = 0; i < n; ++i) {
            if(s[i] != '0') {
                System.out.printf("%c", s[i]);
            }
        }
        System.out.println();
    }
    
    
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;
 
        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
        String next() throws IOException {
            while (st == null || !st.hasMoreElements())
                st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }
        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }
        long nextLong() throws IOException {
            return Long.parseLong(next());
        }
        double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
        String nextLine() throws IOException {
            String str = "";
            str = br.readLine();
            return str;
    }}
 
}
