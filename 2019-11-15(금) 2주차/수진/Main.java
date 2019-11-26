package 일이삼더하기;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	static int[] num;
	static int count;
	
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		int T;
		
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		T=Integer.parseInt(br.readLine().trim());
		num=new int[T];
		
		for(int t=0;t<T;t++) {
			num[t]=Integer.parseInt(br.readLine().trim());
			
		}
		
		for(int t=0;t<T;t++) {
			int sum=0;
			count=0;
			
			dfs(num[t],sum);
			System.out.println(count);
		}
		 
		
		
	}


	private static void dfs(int num, int sum) {
		
		if(sum==num) {

			count++;
			return;
			
		//sum이 num값을 넘어가면 종료시킴	
		}else if(sum>=num) {
			return;
		}
		
		
		for(int i=1;i<=3;i++) {
			sum+=i;
			
			dfs(num,sum);
			sum-=i;
		}
		
			
	}


	

}
