package 다음순열;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

//다음 순열 찾기 알고리즘
// 1. i찾기 -> A[i-1] < A[i]를 만족
// 2. j찾기 -> j>=i && A[j] > A[i-1]
// 3. SWAP A[i-1] AND A[j]
// 4. 순열 뒤집기 -> A[i]부터 오른쪽인 것들 
public class Ans {
	
	static int[] num;
	static int N;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		N=Integer.parseInt(br.readLine().trim());
		num=new int[N+1];
		
		
		StringTokenizer st=new StringTokenizer(br.readLine().trim()," ");
		for(int i=1;i<=N;i++) {
			num[i]=Integer.parseInt(st.nextToken());
		}
		int i,j;
		for(i=N;i>0;i--) {
			if(num[i]>num[i-1]) {
				break; 
			}
		}
		if(i<=1) {
			System.out.println("-1");
			return;
		}
		for(j=N;j>0;j--) {
			if(num[j]>num[i-1] && i<=j) {
				break;
			}
		}
		
		int temp=num[i-1];
		num[i-1]=num[j];
		num[j]=temp;
		
		
		//4. 자리 바꾸기
		j=num.length-1;
		 while (i < j) {
	            temp = num[i];
	            num[i] = num[j];
	            num[j] = temp;
	            i += 1;
	            j -= 1;
	        }

		 for(i=1;i<=N;i++) {
			 
			 System.out.print(num[i]+" ");
		 }
		
		
	}

	
	
}
