package com.ssafy;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class SWEA_5656 {

	/*
	 * 크기가 별로 크지가 않은데 3초나 줌
	 * W를 중복순열로 하여 모든경우를 다 따져보는것도 괜찮을것같은데
	 */
	static class box{
		int x;
		int y;
		int v;
		box(int x, int y, int v){
			this.x = x;
			this.y = y;
			this.v = v;
		}
	}
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static int T, N, W, H, arr[][], tmparr[][], minv;
	static int dx[] = {1, -1, 0, 0};
	static int dy[] = {0, 0, 1, -1};
	static Queue<box>q = new LinkedList<>();
	
	static void init() throws Exception{
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		W = Integer.parseInt(st.nextToken());
		H = Integer.parseInt(st.nextToken());
		arr = new int[H][W];
		
		for (int i = 0; i < H; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < W; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
	}
	static boolean isValid(int x, int y) {
		return (x >= 0 && y >= 0 && x < H && y < W);
	}
	
	static void clean() {
		for (int i = 0; i < W; i++) {
			for (int j = H-1; j > 0; j--) {
				if(tmparr[j][i] == 0) {
					for (int h = j-1; h >= 0; h--) {
						if(tmparr[h][i] != 0) {
							tmparr[j][i] = tmparr[h][i];
							tmparr[h][i] = 0;
							break;
						}
					}
				}
			}
		}
	}
	
	static void q_pop() {
		while(!q.isEmpty()) {
			int x = q.peek().x;
			int y = q.peek().y;
			int v = q.peek().v;
			q.poll();
			
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < v; j++) {
					int mx = x + (dx[i] * j);
					int my = y + (dy[i] * j);
					
					if(isValid(mx,my) && tmparr[mx][my] > 0) {
						q.add(new box(mx, my, tmparr[mx][my]));
						tmparr[mx][my] = 0;
					}
				}
			}
		}
		clean();
	}
	
	static void crash(int chk[]) {
		tmparr = new int[H][W];
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
				tmparr[i][j] = arr[i][j];
		
		for(int i = 0; i < N; i++) {
			int x = chk[i];
			for (int y = 0; y < H ; y++) {
				if(tmparr[y][x] > 0) {
					q.add(new box(y, x, tmparr[y][x]));
					tmparr[y][x] = 0;
					break;
				}
			}
			q_pop();
		}
		int cnt = 0;
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
				if(tmparr[i][j] > 0) cnt++;
		
		if(cnt < minv) minv = cnt;
		
	}
	
	static void find(int chk[], int n) {
		if (n == N) {
			// chk 안에 순열 완성 -> 해당 순열을 활용하여 벽돌깨기 시작
			crash(chk);
			return;
		}
		
		for (int i = 0; i < W; i++) {
			chk[n] = i;
			find(chk, n+1);
		}
	}
	
	public static void main(String[] args) throws Exception{
		T = Integer.parseInt(br.readLine());
		for (int TC = 1; TC <= T; TC++) {
			minv = 2147483647;
			init();	// 입력
			
			find(new int[N], 0);
			System.out.println("#"+TC + " " + minv);
		}
	}
}
