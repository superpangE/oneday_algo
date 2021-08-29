package com.ssafy;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BJ_7569 {
	/*
	 * 토마토 상태가 저장되어 있는 arr 배열 -> 차례로 H(높이), N(세로), M(가로) 임
	 * 델타가 6방을 확인해야함. 확인하는 동시에 1로 토마토가 차있는 곳은 큐에 집어넣기 + isVisited 체크
	 * 전체가 돌고 난 뒤, 큐에서 전체를 빼면서 arr 바꾸기
	 * 큐에서 다 뺐을때, arr 에 '0' 이 존재하는지 확인
	 */
	static class pos{
		int x, y, z, cnt;
		pos(int x, int y, int z, int cnt){
			this.x = x;
			this.y = y;
			this.z = z;
			this.cnt = cnt;
		}
	}
	static int M, N, H, arr[][][];
	static boolean isVisited[][][];
	static int dx[] = {1, -1, 0, 0, 0, 0};
	static int dy[] = {0, 0, 1, -1, 0, 0};
	static int dz[] = {0, 0, 0, 0, 1, -1};
	static int res;
	static Queue<pos>q = new LinkedList<>();
	
	static boolean isValid(int x, int y, int z) {
		return (x >= 0 && y >= 0 && z >= 0 && x < H && y < N && z < M);
	}
	static void bfs() {
		while (!q.isEmpty()) {
			int x = q.peek().x;
			int y = q.peek().y;
			int z = q.peek().z;
			int cnt = q.peek().cnt;
			q.poll();
			for (int i = 0; i < 6; i++) {
				int mx = x + dx[i];
				int my = y + dy[i];
				int mz = z + dz[i];
				if (!isValid(mx, my, mz) || isVisited[mx][my][mz] || arr[mx][my][mz] != 0) continue;
				arr[mx][my][mz] = 1;
				isVisited[mx][my][mz] = true;
				res = cnt + 1;
				q.add(new pos(mx, my, mz, cnt + 1));
			}
		}
	}
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		M = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());
		H = Integer.parseInt(st.nextToken());
		
		arr = new int[H][][];
		isVisited = new boolean[H][][];
		for (int i = 0; i < H; i++) {
			arr[i] = new int[N][];
			isVisited[i] = new boolean[N][];
			for (int j = 0; j < N; j++) {
				arr[i][j] = new int[M];
				isVisited[i][j] = new boolean[M];
				st = new StringTokenizer(br.readLine());
				for (int h = 0; h < M; h++) {
					arr[i][j][h] = Integer.parseInt(st.nextToken());
					if (arr[i][j][h] == 1) {		// 좌표가 1이면 Queue 에 삽입 + isVisited 체크
						q.add(new pos(i, j, h, 0));
						isVisited[i][j][h] = true;
					}
				}
			}
		}		// 입력완료

		bfs();
		
		boolean flag = false;
		for (int i = 0; i < H; i++) {
			for (int j =0; j < N; j++) {
				for (int h = 0; h < M; h++) {
					if (arr[i][j][h] == 0) {
						flag = true;
						i = H; j = N; h = M;
					}
				}
			}
		}
		if (flag) System.out.println("-1");
		else System.out.println(res);
	}

}
