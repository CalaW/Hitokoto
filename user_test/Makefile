main: main.o AdminUser.o Cipher.o EncryptStrategy.o Md5.o TrivialUser.o User.o
	clang++ $^ -o $@
debug:
	clang++ main.cpp AdminUser.cpp Cipher.cpp EncryptStrategy.cpp Md5.cpp TrivialUser.cpp User.cpp -o $@ -g -std=c++11
main.o: main.cpp
	clang++ -c $< -o $@ -std=c++11
AdminUser.o: AdminUser.cpp AdminUser.h
	clang++ -c $< -o $@ -std=c++11
Cipher.o: Cipher.cpp Cipher.h
	clang++ -c $< -o $@ -std=c++11
EncryptStrategy.o: EncryptStrategy.cpp EncryptStrategy.h
	clang++ -c $< -o $@ -std=c++11
Md5.o: Md5.cpp Md5.h
	clang++ -c $< -o $@ -std=c++11
TrivialUser.o: TrivialUser.cpp TrivialUser.h
	clang++ -c $< -o $@ -std=c++11
User.o: User.cpp User.h
	clang++ -c $< -o $@ -std=c++11
