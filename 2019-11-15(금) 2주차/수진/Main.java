package 시험감독;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int N;
	static int[] A;
	static int B,C;
	
	//int - 4byte, long - 8byte
	//type은 long으로 해준다.
	//100만명의 학생들이 100만개 시험장에 들어가 있는데 =3바이트내
	//최악은 총 감독관이 100만 *100만 만큼 필요하게 된다. =5바이트 
	static long count=0;
	
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		N=Integer.parseInt(br.readLine().trim());
		A=new int[N];
		
		
		StringTokenizer st=new StringTokenizer(br.readLine().trim()," ");
		for(int i=0;i<N;i++) {
			A[i]=Integer.parseInt(st.nextToken());
		}
		
		st=new StringTokenizer(br.readLine().trim()," ");
		B=Integer.parseInt(st.nextToken());
		C=Integer.parseInt(st.nextToken());
		
		for(int i=0;i<N;i++) {
			countPeople(i);
		
		}
		
		System.out.println(count);
	}


	private static void countPeople(int index) {
		A[index]-=B;
		count++;
		
		
		
		if(A[index]>0) {
			int M=A[index]/C;
			int NM=A[index]%C;
			count+=M;
			
			if(NM>0 &&NM<C)count++;
		}
		
	}
}
