// * 테트로미노
package BruteForce;

import java.util.*;
public class B_14500 {
	
	static int[][] a;
	static boolean[][] c; // 방문 여부 확인
	static int n, m;
	static int[] dx = {0, 0, 1, -1};
	static int[] dy = {1, -1, 0, 0};
	static int ans = 0; // 최대 합
	
	// dfs탐색
	static void go(int x, int y, int sum, int cnt) {
				
		// 4번째 폴리오미노까지 만들어졌을 때
		if (cnt == 4) {
			if (ans < sum)
				ans = sum;
			return;
		}
		
		// 종이의 범위를 넘어갔을 때
		if (x < 0 || x >= n || y < 0 || y >= m)
			return;
		
		// 이미 방문 했다면 -> 되돌아감
		if (c[x][y])
			return;
		
		// 방문 표시
		c[x][y] = true;
		
		// 다음 방문 좌표
		for (int k = 0; k < 4; k++) {
			go(x + dx[k], y + dy[k], sum + a[x][y], cnt + 1);
		}
		
		//
		c[x][y] = false;
	}
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		n = sc.nextInt(); // 종이의 세로크기
		m = sc.nextInt(); // 종이의 가로크기
		a = new int[n][m]; 
		c = new boolean[n][m];
		
		// 종이에 쓰여질 수 입력
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				a[i][j] = sc.nextInt();
			}
		}	
		// i번째 줄과 j번째 수 차례로 탐색
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				
				go(i, j, 0, 0);
				
				if (j+2 < m) {				
					int temp = a[i][j] + a[i][j+1] + a[i][j+2];
					
					if (i-1 >= 0) {
						int temp2 = temp + a[i-1][j+1];
						if (ans < temp2) ans = temp2;
					}
					if (i+1 < n) {
						int temp2 = temp + a[i+1][j+1];
						if (ans < temp2) ans = temp2;
					}
				}
				if (i+2 < n) {
					int temp = a[i][j] + a[i+1][j] + a[i+2][j];
					
					if (j+1 < m) {
						int temp2 = temp + a[i+1][j+1];
						if (ans < temp2)
							ans = temp2;
					}
					
					if (j-1 >= 0) {
						int temp2 = temp + a[i+1][j-1];
						if (ans < temp2)
							ans = temp2;
					}
				}
			}
		}
		System.out.println(ans);
	}
}