/*
 * 무조건 간다 ? 메모리초과가 나는데 바꿀수있는게 있을까
 * 갔을때 자기보다 적은값을 만난다면 poll 하는것 보다 적은 수가 있을까
 * 모든정보를 가지고 가는건 더 느릴거같은데
 * 아니면 p-queue를 사용하는것은 어떠할까 -> ㄱㄱ
 */

import java.util.*;
import java.io.*;

public class Main {
	static class box implements Comparable<box>{
		int x;
		int y;
		int val;
		box(int x, int y, int val){
			this.x = x;
			this.y = y;
			this.val = val;
		}
		@Override
		public int compareTo(box o) {
			return (this.val - o.val);
		}
	}
	static int dx[] = {0, 0, 1, -1};
	static int dy[] = {1, -1, 0, 0};
	static int N;
	static PriorityQueue<box>pq = new PriorityQueue<>();
	static int arr[][], dp[][];
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
	static void init() throws Exception{
		arr = new int[N][N];
		dp = new int[N][N];
		for (int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int j = 0 ; j < N; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
				dp[i][j] = 217483647;
			}
		}
		dp[0][0] = arr[0][0];
		pq.add(new box(0, 0, dp[0][0]));
	}
	
	static boolean isValid(int x, int y) {
		return (x >= 0 && y >= 0 && x < N && y < N);
	}
	
	static void bfs() {
		while (!pq.isEmpty()) {
			int x = pq.peek().x;
			int y = pq.peek().y;
			int val = pq.peek().val;
			pq.poll();
			
			for (int i = 0; i < 4; i++) {
				int mx = x + dx[i];
				int my = y + dy[i];
				if(isValid(mx, my) && ((arr[mx][my] + val) < dp[mx][my])) {
					dp[mx][my] = arr[mx][my] + val;
					if(mx == N-1 && my == N-1) return;
					pq.add(new box(mx, my, dp[mx][my]));
				}
			}
		}
	}
	
	public static void main(String[] args) throws Exception{
		int cal = 1;
		while((N = Integer.parseInt(br.readLine())) > 0) {
			pq.clear();
			init();
			bfs();
			System.out.println("Problem " + cal++ + ": " + dp[N-1][N-1]);

		}
	}
}
