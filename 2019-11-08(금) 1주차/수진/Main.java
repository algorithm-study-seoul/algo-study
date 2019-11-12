package ÀÏ°ö³­ÀïÀÌ;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Main {
	
	static int[] man=new int[9];
	
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		ArrayList<Integer> result=new ArrayList<>();
		
		//ÀÔ·Â
		for(int i=0;i<9;i++) {
			man[i]=sc.nextInt();
		}
		forout:
		for(int i=0;i<9;i++) {
			for(int j=i+1;j<9;j++) {
				
				int sum=0;
				
				for(int k=0;k<9;k++) {
					
					if(k!=i && k!=j) {
						sum+=man[k];
					}
				}
				
				
				if(sum==100) {
					for(int k=0;k<9;k++) {
						if(k!=i && k!=j) {
							result.add(man[k]);
						}
					}
					break forout;
					
				}
			}
		}
		
		Collections.sort(result);


		for(int i=0;i<result.size();i++) {
			System.out.println(result.get(i));
		}
	}
}
