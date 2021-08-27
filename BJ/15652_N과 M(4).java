package com.ssafy;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BJ_15652 {
	static int N, M, arr[];
	static void perm(int idx, int nxt) {
		if (idx == M) {
			for (int i = 0; i < M; i++)
				System.out.print(arr[i]+ " ");
			System.out.println();
			return ;
		}
		for (int i = nxt; i <= N; i++) {
			arr[idx] = i;
			perm(idx + 1, i);
		}
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		arr = new int[M];
		perm(0, 1);
	}
}
