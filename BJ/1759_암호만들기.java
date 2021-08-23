package com.ssafy;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;
/*
 * 입력을 받아 char 배열에 집어넣고 오름차순으로 정렬.
 * L 크기만큼의 res 배열을 만들어 char 배열을 조합으로 L 만큼을 뽑는다
 * L 크기만큼 뽑았다면 출력 + 개행을 한다.
 * 반복
 */
public class BJ_1759 {
	static int L, C;
	static char arr[], res[];
	
	public static void comb(int idx, int next) {
		if (idx == L) {
			// 모음 1개 이상, 자음 2개 이상인지 확인
			int cnt1 = 0, cnt2 = 0;
			for (int i = 0; i < idx; i++) {
				if (res[i] == 'a' || res[i] == 'e' || res[i] == 'o' || res[i] == 'i' || res[i] == 'u') cnt1++;
				else cnt2++;
			}
			if (cnt1 >= 1 && cnt2 >= 2) {
				for (int i = 0; i < idx; i++)
					System.out.print(res[i]);
				System.out.println();
			}
			return ;
		}
		
		for (int i = next; i < C; i++) {
			res[idx] = arr[i];
			comb(idx + 1, i + 1);
			
		}
		
	}
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		L = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		
		arr = new char[C];
		res = new char[L];
		st = new StringTokenizer(br.readLine());
		for (int i = 0 ; i < C; i++)
			arr[i] = st.nextToken().charAt(0);	// 입력완료
		
		Arrays.sort(arr);		// 오름차순 정렬
		
		comb(0, 0);
	}
}
