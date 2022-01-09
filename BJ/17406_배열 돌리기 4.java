import java.util.*;
import java.io.*;

public class Main{
	static class box{
		int r;
		int c;
		int s;
		box(int r, int c, int s){
			this.r = r;
			this.c = c;
			this.s = s;
		}
	}
	static Queue<box>q = new LinkedList<>();
	static int N, M, K, minv = 2147483647;
	static int arr[][], tmp[][], ini[][];
	static box b[];
	static void init() throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		
		arr = new int[N][M];
		tmp = new int[N][M];
		ini = new int[N][M];
		b = new box[K];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				ini[i][j] = tmp[i][j] = arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		for (int i = 0; i < K; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b1 = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			b[i] = new box(a, b1, c);
		}
	}
	static void left(int r, int c, int s) {
		tmp[r-s][c-s + 1] = arr[r-s][c-s];
		for(int i = -s; i < s; i++) {
			tmp[r+i][c-s] = arr[r+i+1][c-s];
		}
	}
	
	static void up(int r, int c, int s) {
		tmp[r-s+1][c+s] = arr[r-s][c+s];
		for(int i = -s; i < s; i++) {
			tmp[r-s][c-i] = arr[r-s][c-i-1];
		}
	}
	
	static void right(int r, int c, int s) {
		tmp[r+s][c+s-1] = arr[r+s][c+s];
		for(int i = -s; i < s; i++) {
			tmp[r-i][c+s] = arr[r-i-1][c+s];
		}
	}
	
	static void down(int r, int c, int s) {
		tmp[r+s-1][c-s] = arr[r+s][c-s];
		for(int i = -s; i < s; i++) {
			tmp[r+s][c+i] = arr[r+s][c+i+1];
		}
	}
	
	static void queue() {
		while(!q.isEmpty()) {
			int r = q.peek().r-1;
			int c = q.peek().c-1;
			int s = q.peek().s;
			q.poll();
			
			for (int i = 1; i <= s; i++) {
				// 4방향
				left(r,c,i);
				right(r,c,i);
				up(r,c,i);
				down(r,c,i);
			}
			for(int i = 0 ; i < N; i++) {
				for (int j = 0; j < M; j++) {
					arr[i][j] = tmp[i][j];
				}
			}
		}
		for (int i = 0; i < N; i++) {
			int tmp = 0;
			for (int j = 0 ; j < M; j++) {
				tmp += arr[i][j];
			}
			if (tmp < minv) minv = tmp;
		}
		
	}
	static void perm(int[] output, boolean[] visited, int depth) {
		if(depth == K) {
			for (int i = 0 ; i < N; i++) {
				for (int j = 0; j < M; j++) {
					tmp[i][j] = arr[i][j] = ini[i][j];
				}
			}
			for(int i = 0; i < K; i++) {
				q.add(b[output[i]]);
			}
			queue();
			return;
		}
		for (int i = 0; i < K; i++) {
			if(!visited[i]) {
				visited[i] = true;
				output[depth] = i;
				perm(output, visited, depth+1);
				visited[i] = false;
			}
		}
	}
	public static void main(String[] args) throws Exception{
		init();
		perm(new int[K], new boolean[K], 0);
		System.out.println(minv);
		
	}
}
