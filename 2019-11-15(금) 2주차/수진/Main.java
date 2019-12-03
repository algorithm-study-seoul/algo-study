package 차이를최대로;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	static int N;
	static int[] num;
	static int[] num2;
	static int[] num3;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br =new BufferedReader(new InputStreamReader(System.in));
		
		
		N=Integer.parseInt(br.readLine().trim());
		
		num=new int[N];
		num2=new int[N];
		num3=new int[N];
		
		StringTokenizer st=new StringTokenizer(br.readLine().trim()," ");
		for(int i=0;i<N;i++) {
			num[i]=Integer.parseInt(st.nextToken());
		}
		
		Arrays.parallelSort(num);

		
		int count=0;
		int i,j,a,b;
		
		i=(N/2)-1;
		j=N/2;
		

		
		for(a=0, b=N-1;i>=0&&j<N;i--,j++,a++,b--) {
				if(count%2==0) {
					num2[i]=num[a];
					num2[j]=num[b];
					
				}
				else {
					num2[i]=num[b];
					num2[j]=num[a];
				}
				
			
			count++;
		}
		
		
		if(N%2!=0) {
			num2[N-1]=num[a];
			i=(N/2);
			j=(N/2)+1;

			count=0;
			for(a=0, b=N-1;i>=0&&j<N;i--,j++,a++,b--) {
//				System.out.println(num[a]+" and "+num[b]+i+"  "+j);
					if(count%2==0) {
						num3[i]=num[a];
						num3[j]=num[b];
						
					}
					else {
						num3[i]=num[b];
						num3[j]=num[a];
					}
					
				
				count++;
			}
			num3[0]=num[a];
		}
			
		

//		for(int k=0;k<N;k++) {
//			System.out.print(num2[k]+" ");
//		}
//		System.out.println();
//		for(int k=0;k<N;k++) {
//			System.out.print(num3[k]+" ");
//		}
//		System.out.println();
		
		int cha1=0;
		int cha2=0;
		for(int k=0;k<N-1;k++) {
			cha1+=Math.abs(num2[k]-num2[k+1]);
			cha2+=Math.abs(num3[k]-num3[k+1]);
			
		}
		
		System.out.println(Math.max(cha1,cha2));
	}
}
