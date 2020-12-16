# -I include header files then compile in src directory
gcc -I/home/tony/Desktop/My_repos/Clang_sandbox/includes/ test_linked_list.c linked_list.c  -o test_linked_list
gcc -E src/mock_p.c
gcc -c src/mock_p.c 
gcc -g src/mock_p.c -o mockp 
gcc -g src/mock_p.c -o mockp -lm # for math