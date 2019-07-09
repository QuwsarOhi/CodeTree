import java.math.BigInteger;
import java.util.*;
 
public class Main{
 
    public static BigInteger a[] = new BigInteger[100010];
    public static BigInteger temp, total, btemp, btemp1,btemp2,ftemp,mini;
    public static int n,m,pos,tt;
 
 
 
    public static BigInteger T(int from, int pos){
 
        ftemp = BigInteger.valueOf(1);
 
        for(int i=from; i<=pos; i++){
 
            ftemp = ftemp.multiply(a[i]);
        }
 
        return ftemp;
 
    }
 
    public static Integer S(){
 
        int l = 0, r = n-1,ans = n+3;
 
        mini = total;
 
        // System.out.println("GFD223S");
        while(l <= r){
 
            int mid = (r+l)/2;
 
            btemp = T(0, mid);
            btemp1 = T(mid+1, n-1);
 
            btemp2 = btemp.subtract(btemp1);
            btemp2 = btemp2.abs();
 
          //  System.out.println("R  " + mid + "   " + btemp +"  " + btemp1 + "   "+ btemp2);
 
            int check = btemp.compareTo(btemp1);
 
            if(btemp2.compareTo(mini) == -1){
                mini = btemp2;
                ans = mid;
               // System.out.println(ans+ "  " + mini + "   "+ btemp2);
            }
 
 
            if(btemp2.compareTo(mini) == 0){
                if(ans > mid) ans = mid;
               // System.out.println(ans+ "  " + mini + "   "+ btemp2);
            }
 
            if(check == -1){
 
                l = mid+1;
            }
            else {
                r = mid-1;
            }
 
 
 
 
        }
 
        return ans+1;
 
    }
 
     public static void main(String []args) throws Exception {
 
         Scanner input = new Scanner(System.in);
 
         n = input.nextInt();
         m = input.nextInt();
 
         total = BigInteger.valueOf(1);
 
         for(int i=0; i<n; i++) {
             a[i] = input.nextBigInteger();
             total = total.multiply(a[i]);
         }
 
         while( m!= 0 ){
 
             tt = input.nextInt();
 
             if(tt == 1){
 
                pos = input.nextInt();
                pos--;
                temp = input.nextBigInteger();
                a[pos] = a[pos].multiply(temp);
                total = total.multiply(temp);
 
             }
             else{
                // System.out.println("GFDS");
                 System.out.println(S());
             }
         }
 
     }
}
 
 
/*
 
 
8 9
2 2 2 2 2 2 2 2
2
1 3 2
2
1 1 4
2
1 1 8
2
1 8 256
2
*/