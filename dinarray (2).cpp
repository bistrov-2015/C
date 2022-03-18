#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "dinarray.h"

int fd;
int size;
int reserv;
info *db;

int GetSize(){
	return size;
}

bool Init(char* fname){
	fd=open(fname,O_RDWR);
	if(fd==-1)
		return false;
	off_t fsize=lseek(fd,0,SEEK_END);
	if(fsize%sizeof(info))
		return false;
	size=fsize/sizeof(info);
	reserv=size*2;
	db=(info*)malloc(reserv*sizeof(info));
	lseek(fd,0,SEEK_SET);
	read(fd,db,size*sizeof(info));
}

bool Add(info inf){
	if(reserv==size){
		reserv*=2;
		db=(info*)realloc(db,reserv);
		if(db==NULL) return false;
	} else{
	db[size]=inf;
	size++;
	return true;
	}
}
bool Delete(int i){
    if((i>=0) && (i<=size)){
		//memmove(void *dest, const void *src, size_t n);
		//i==size-1  ->0
		//i==0       ->size-1
		memmove(&db[i], &db[i+1], (size-i-1)*sizeof(info));
        size--;
		return true;
    }else
    return false;
}
bool Replace(int i, info inf){
    if((i>=0) && (i<=size-1)){
        db[i]=inf;
	return true;
    }
    else return false;
}
bool Get(int i, info* pinf){
    if((i>=0) && (i<=size-1)){
        *pinf=db[i];
		return true;
    }else{
    return false;};
}

bool Insert (int i, info inf){
    if(!((i>=0) && (i<=size-1))){
		return false;
    }
	if(reserv==size){
		reserv*=2;
		db=(info*)realloc(db,reserv);
		if(db==NULL) return false;
	}
	// i==0  		->size
	// i==sizwe-1	->1
	memmove(&db[i+1], &db[i], (size-i)*sizeof(info));
	db[i]=inf;
	size++;
	return true;
}

bool Save(){
	if(fd==-1)
		return false;
	lseek(fd,0,SEEK_SET);
	write(fd,db,size*sizeof(info));
	return true;
}
