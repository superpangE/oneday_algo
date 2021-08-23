package com.ssafy;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Contact {
	/*
	* N 과 시작점을 받고 N 은 최대 100이니깐 vector 를 100만큼 설정
	* 두개씩 받아서 to -> from 이 되도록 (겹쳐도 상관없음) vector에 삽입
	* int chk[100] 으로 방문했는지 확인을 함(0 이라면 방문한것 숫자가 올라갈수록 몇번째 방문)
	* 첫 시작에서 부터 해당 vector의 값들을 queue 에 집어넣어서 확인
	* 다음 queue 로 갈때는 int chk 값을 1씩 추가해서 하기
	* 최대 거리가 얼마였는지 저장을 따로 함
	* 다 돌고나서 arr 뒤에서부터 돌며 최초로 최대거리에 해당되는 거리가 나왔을 때 값 반환
	*/
	static class Pair{
		int idx;
		int cnt;
		
		Pair(int idx, int cnt){
			this.idx = idx;
			this.cnt = cnt;
		}
	}
	static Queue<Pair>q = new LinkedList<>();
	static ArrayList<Integer> lists[];
	static int N, start, a, b, chk[], maxv;
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		for (int TC = 1; TC <= 10 ; TC++) {
			maxv = -1;
			chk = new int[101];
			lists = new ArrayList[101];
			for (int i = 0; i < 101; i++)
				lists[i] = new ArrayList<>();
			
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			start = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine());
			for (int i = 0 ; i < N / 2; i++) {
				a = Integer.parseInt(st.nextToken());
				b = Integer.parseInt(st.nextToken());
				
				lists[a].add(b);
			}			// 입력 완료
			Pair p = new Pair(start, 1);
			q.add(p);
			chk[start] = 1;
			
			while (!q.isEmpty()) {
				int idx = q.peek().idx;
				int cnt = q.peek().cnt;
				q.poll();
				
				for (int i = 0 ; i < lists[idx].size(); i++) {
					if (chk[lists[idx].get(i)] == 0) {
						chk[lists[idx].get(i)] = cnt + 1;
						q.add(new Pair(lists[idx].get(i) , cnt + 1));
						if ((cnt + 1) > maxv)
							maxv = cnt + 1;
					}
				}
				
			}
			for (int i = 100; i > 0; i--) {
				if (chk[i] == maxv) {
					System.out.println("#" + TC + " " + i);
					break;
				}
			}
		}
	}
}
