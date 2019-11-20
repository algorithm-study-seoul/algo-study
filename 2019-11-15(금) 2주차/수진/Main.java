package ���谨��;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int N;
	static int[] A;
	static int B,C;
	
	
	//type�� long���� ���ش�.
	//100������ �л����� 100���� �����忡 �� �ִµ� 
	//�־��� �� �������� 100�� *100��ŭ �ʿ��ϰ� �ȴ�.
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
