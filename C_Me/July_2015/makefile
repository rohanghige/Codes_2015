all: mul_thr_1 hello_world_threaded mul_thr_2 mul_thr_3 badcnt goodcnt consm_prod que_case

mul_thr_1: mul_thr_1.c
	gcc -o mul_thr_1 mul_thr_1.c -lpthread
	
mul_thr_2: mul_thr_2.c
	gcc -o mul_thr_2 mul_thr_2.c -lpthread	

mul_thr_3: mul_thr_3.c
	gcc -o mul_thr_3 mul_thr_3.c -lpthread	
	
badcnt: badcnt.c
	gcc -o badcnt badcnt.c -lpthread -lrt
	
goodcnt: goodcnt.c
	gcc -o goodcnt goodcnt.c -lpthread	-lrt	

consm_prod: consm_prod.c
	gcc -o consm_prod consm_prod.c -lpthread	-lrt
		
hello_world_threaded: hello_world_threaded.c
	gcc -o hello_world_threaded hello_world_threaded.c -pthread
que_case: que_case.c
	gcc -o que_case que_case.c
