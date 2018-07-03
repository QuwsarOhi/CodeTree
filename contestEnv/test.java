import java.util.Scanner;
public class test {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		test tr = new test();
		tr.test(sc);
		sc.close();
	}
	void test(Scanner sc){
		int A = sc.nextInt();
		int B = sc.nextInt();
		int X = sc.nextInt();
		int more = A>=B?A:B;
		char MORE = A>=B?'0':'1';
		int less = A+B-more;
		char LESS = MORE=='0'?'1':'0';
		char[] out = new char[A+B];
		
		int i = 0;
		int x=0;
		int m=0;
		int l=0;
		if(X==1){
			for ( i = 0; i < more; i=i+1) {
				out[i]=MORE;
			}
			for ( ; i < more+less; i=i+1) {
				out[i]=LESS;
			}
			for ( int ii = 0; ii < A+B; ii=ii+1) {
				System.out.print(out[ii]+"");
			}
			return;
		}
		
		if(X==2){
			out[i++]=MORE;
			while(l<less&& i < A+B){
				out[i++] = LESS;
				l++;
			}
			while(m<more&& i < A+B){
				out[i++] = MORE;
				m++;
			}
			
			for ( int ii = 0; ii < A+B; ii=ii+1) {
				System.out.print(out[ii]+"");
			}
			return;
		}
		

		for ( i = 0; x < X-2; i=i+2) {
			out[i]=MORE;m++;
			out[i+1]=LESS;l++;
			x= (i== 0?x+1:x+2);
		}
	//	int rem= A+B-i-2;
		int last = out[i-1];
		if(x==X-1){
			// repeat last one and then other
			if(last==MORE){
				while(m<more && i < A+B){
					out[i++] = MORE;
					m++;
				}
				while(l<less&& i < A+B){
					out[i++] = LESS;
					l++;
				}
			}
			else{

				while(l<less&& i < A+B){
					out[i++] = LESS;
					l++;
				}
				while(m<more&& i < A+B){
					out[i++] = MORE;
					m++;
				}
			}
			
		}else{
			// repeat other one and then last
			if(last==MORE){
				while(l<less&& i < A+B){
					out[i++] = LESS;
					l++;
				}
				while(m<more&& i < A+B){
					out[i++] = MORE;
					m++;
				}
			}
			else{
				while(m<more&& i < A+B){
					out[i++] = MORE;
					m++;
				}
				while(l<less&& i < A+B){
					out[i++] = LESS;
					l++;
				}
			}
		}
/*		for (int r=0; r < rem; r++) {
			out[i]=more;
			i++;
		}*/
		
		for ( i = 0; i < A+B; i=i+1) {
			System.out.print(out[i]+"");
		}

	}
}
