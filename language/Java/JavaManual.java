// Default Import 
//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.StringTokenizer;

import java.io.*;
import java.util.*;

class team implements Comparable<team> {                            // struct team
    int id, solved, penalty;

    public team(int id, int solved, int penalty) {
        this.id = id; this.solved = solved; this.penalty = penalty;
    }
    public int compareTo(team o) {                                          // Compatison Function for sorting!! [ THIS FUNCTION NAME IS FIXED!! ]
        if(solved != o.solved) return o.solved - solved;                    // ICPC rule: sort by number of problem solved  - > +
        else if(penalty != o.penalty)   return penalty - o.penalty;         // ICPC rule: sort by descending penalty        + > -
        else return id - o.id;                                              // sort based on increasing team ID             - > +
    }
    public String toString() {
        return "id: " + id + ", solved: " + solved + ", penalty: " + penalty;
}}

public class JavaManual {
    
    // ------------------------------- Fast Read Method -------------------------------
    
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
 
    // ------------------------------- Stack / Queue / Deque -------------------------------
    
    static void STACK() {
        Stack<Character> s = new Stack<Character>();
        System.out.println(s.isEmpty());            // currently s is empty, true
        System.out.println(s.size());               // Size of Stack
        s.push('a'); s.push('b'); s.push('c');
        
        while(!s.isEmpty()) {                         // Looping in Stack
            System.out.println(s.peek());             // use peek() to see the top stack element
            s.pop();                                  // pop operation
    }}
        
    static void QUEUE() {
        // Queue is abstract, must be instantiated with LinkedList (special case for Java Queue)
        Queue<Character> q = new LinkedList<Character>();
        q.offer('b'); q.offer('a');         // enqueue 'b' then 'a' (the method name in Java Queue for push/enqueue operation is 'offer')
        System.out.println(q.isEmpty());            // currently q is empty, true
        System.out.println(q.size());               // queue size
        System.out.println(q.peek());               // prints front element of queue
        
        while(!q.isEmpty()) {                               // queue loop               [ q.empty() doesn't exist in java! ]
            System.out.printf("%c\n", q.peek());            // take the front first
            q.poll();                                       // before popping (dequeue-ing) it
    }}
        
    static void DEQUE() {
        // Deque is abstract, must be instantiated with LinkedList (special case for Java Queue)
        Deque<Character> d = new LinkedList<Character>();
        d.addLast('a'); d.addLast('b'); d.addLast('c');                 // addLast adds element on last, addFast adds on first
        System.out.printf("%c - %c\n", d.getFirst(), d.getLast());      // prints 'a - c'
        d.addFirst('d');
        System.out.printf("%c - %c\n", d.getFirst(), d.getLast());      // prints 'd - c'
        d.pollLast();                                                   // pop out last element
        System.out.printf("%c - %c\n", d.getFirst(), d.getLast());      // prints 'd - b'
        d.pollFirst();                                                  // pop out first element
        System.out.printf("%c - %c\n", d.getFirst(), d.getLast());      // prints 'a - b'
    }

    // ------------------------------- Vector + Collection -------------------------------
    
    static void TEST() {
        int[] arr = new int[] {2, 1, 10, 3};                                        // Array creation
        Vector<Integer> v = new Vector<Integer>(Collections.nCopies(5, -1));        // Vector size 5, initially all are -1
        
        System.out.printf("Vector Size : %d\n", v.size());
        for(int i = 0; i < v.size(); ++i) System.out.println(v.get(i));             // Default loop
        v.add(101); v.add(11111); v.add(945);                                       // adding element in vector
        for(int x : v) System.out.println(x);                                       // For Each loop
        v.remove(v.size()-1);                                                       // removing value at index
        v.add(1, 19);                                                               // inserting element at index 1
        System.out.printf("Last Element %d\n", v.lastElement());                    // Last Element
        
        Collections.sort(v);                                                        // Sorting Vector  [Supports in all linear DS]
        // binarySearch will return: index of the search key, if it is contained in the list; otherwise, (-(insertion point) - 1).
        System.out.printf("BS : %d\n", Collections.binarySearch(v, 19));            // Binary Search
        Collections.reverse(v);                                                     // Reverse
        Collections.shuffle(v);                                                     // Shuffle
        v.clear();                                                                  // Clear vector
        
        Vector<team> T = new Vector<team>();                                        // user defined struct vector
        T.add(new team(1, 1, 10)); T.add(new team(2, 3, 60)); T.add(new team(3, 1, 20)); T.add(new team(4, 3, 60));
        Collections.sort(T);                                                        // Sort using Coparator of struct
        for(int i = 0; i < T.size(); ++i)
            System.out.println(T.get(i));
        
        System.out.printf("%d, %d\n", Math.min(10, 11), Math.max(10, 11));
        
        Vector<Stack<Integer>> st = new Vector<Stack<Integer>>();                   // Array of stack is not possible, using vector
        st.setSize(26);                                                             // Declaring size by default (all unused are null)
        System.out.println(st.get(0) == null);                                      // check if empty/null
    }
    
    public static void main(String[] args) throws IOException {             // exception is for fileIO
        //PrintWriter pw = new PrintWriter(new File("out"));
        //pw.printf("Writing in file");                                     // File Output Method
        //Scanner input = new Scanner(new File("in"));                      // File Input Method (Use System.in of STDIN input)

        // Scanner input = new Scanner(System.in);
        // FastReader fr = new FastReader();

        System.out.printf("WORKED!!\n"); TEST();
        
        //pw.close();           // Close File if PrintWriter is used!
}}
