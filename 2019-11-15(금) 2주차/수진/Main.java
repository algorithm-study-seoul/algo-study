package 외판원순회2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	
	static int N;
	static int[][] num;
	static boolean[] v;
	static int min=Integer.MAX_VALUE;
	static int start;

	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		
		N=Integer.parseInt(br.readLine().trim());
		
		num=new int[N][N];
		v=new boolean[N];
		
		for(int i=0;i<N;i++) {
			StringTokenizer st=new StringTokenizer(br.readLine().trim()," ");
			for(int j=0;j<N;j++) {
				num[i][j]=Integer.parseInt(st.nextToken());
			}
		}
		
		

		for(int i=0;i<N;i++) {
			v[i]=true;
			start=i;
			
			dfs(i,1,0);
			
			v[i]=false;
		}
		System.out.println(min);
		
		
	}

	private static void dfs(int index, int count, int tmp) {

		if(count==N && num[index][start]!=0) {
			tmp+=num[index][start];
			//System.out.println(min);
			if(min>tmp) {
				min=tmp;
			}
			tmp-=num[index][start];

			return;
		}
		
		for(int i=0;i<N;i++) {
			
			if(!v[i] && num[index][i]!=0) {
				v[i]=true;
				count++;
				tmp+=num[index][i];
				//System.out.print(tmp+" ");
				dfs(i,count,tmp);
				
				v[i]=false;
				count--;
				tmp-=num[index][i];
			}
		}
		
	}

}
