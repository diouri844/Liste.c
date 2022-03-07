#include<stdio.h>
#include<stdlib.h>
#include"Liste.hpp"

// Implementation : 

Liste::Liste(){
    this->length = 0;
    this->tab = (float*)malloc(0*sizeof(float));
}

Liste::Liste(int len){
    this->length = len;
    this->tab = (float*)malloc(this->length*sizeof(float));
    for(int i=0;i<this->length;i++){
        printf("\n %d) : ",i+1);
        scanf("%f",&this->tab[i]);
    }
}

Liste::Liste(int len, int nbr){
    this->length = len;
    this->tab = (float*)malloc(this->length*sizeof(float));
    for(int i=0;i<this->length;i++){
        this->tab[i] = nbr;
    }
}

int Liste::len(){
    return this->length;
}

void Liste::see(){
    for(int i=0;i<this->length;i++){
        printf("\n %d) %.2f ",i+1,this->tab[i]);
    }
    return;
}

float Liste::max(){
    float max = this->tab[0];
    for(int i=1;i<this->length;i++){
        if(this->tab[i]>max){
            max = this->tab[i];
        }
    }
    return max;
}

float Liste::max(int index){
    if(index < this->length){
        float max = this->tab[0];
        for(int i=1;i<index;i++){
            if(this->tab[i]>max){
                max = this->tab[i];
            }
        }
    return max;
    }
    return (float)-1;
}

void Liste::see(int index){
    if(index <= this->length){
        for(int i=0;i<index;i++){
        printf("\n %d) %.2f ",i,this->tab[i]);
        }
    }
    return;
}

float Liste::get(int index){
    if(index <= this->length){
        return this->tab[index];
    }
    return (float)-1;
}

int Liste::index(float item){
    for(int i=0;i<this->length;i++){
        if(this->tab[i]==item){
            return i;
        }
    }
    return-1;
}

void Liste::set(float item, int index){
    if(index <= this->length){
        this->tab[index] = item;
    }
    return;
}

float Liste::max(int in_start,int in_end){
    if(in_start < this->length && in_end <= this->length){
        float max = this->tab[in_start];
        for(int i=in_start;i<=in_end;i++){
            if(this->tab[i]>max){
                max = this->tab[i];
            }
        }
        return max;
    }
    return (float)-1;
}

float Liste::min(){
    float min = this->tab[0];
    for(int i=1;i<this->length;i++){
        if(this->tab[i]<min){
            min = this->tab[i];
        }
    }
    return min;
}  

float Liste::min(int index){
    if(index < this->length){
        float min = this->tab[0];
        for(int i=1;i<index;i++){
            if(this->tab[i]<min){
                min = this->tab[i];
            }
        }
    return min;
    }
    return (float)-1;
}

float Liste::min(int  in_start, int in_end){
    if(in_start < this->length && in_end <= this->length && in_start<in_end){
        float min = this->tab[in_start];
        for(int i=1;i<in_end;i++){
            if(this->tab[i]<min){
                min = this->tab[i];
            }
        }
        return min;
    }
    return (float)-1;
}

void Liste::append(float item){
    // add new item in end of array:
        ++this->length;
        // realocation du memoire :
            this->tab = (float*)realloc(this->tab,this->length*sizeof(float));
        // add item :
            this->tab[this->length-1] = item;
    return;
}

void Liste::insert(int index, float item){
    if(index< this->length){
    float originale_value = this->tab[index];
    float* temp = (float*)malloc(this->length*sizeof(float));
    for(int i=0;i<this->length;i++){
            temp[i]=this->tab[i];
        }
    // update len:
    ++this->length;
    // realloc :
    this->tab = (float*)realloc(this->tab,this->length*sizeof(float));
    this->tab[index] = item;
    int current = 1;
    for(int i=index+1;i<=this->length;i++){
        this->tab[i] = originale_value;
        originale_value = temp[i];
        }
    }
    return;
}

void Liste::pop(){
    // remove the last item of liste : 
    --this->length;
    this->tab = (float*)realloc(this->tab,this->length*sizeof(float));
    return;   
}

void Liste::delet(int index){
    // set item index in the end : 
    if(index< this->length){
        float temp = this->tab[this->length-1];
        this->tab[this->length-1]=this->tab[index];
        this->tab[index]= temp;
        this->pop();
        for(int i=index;i<this->length-1;i++){
            float temp = this->tab[i+1];
            this->tab[i+1]=this->tab[i];
            this->tab[i]= temp;
        }
    }
    return;
}

void Liste::sort(bool reverse){
    if(reverse==true){
        // min ----> max :
        for(int count=0;count<this->length;count++){
            for(int i=0;i<this->length;i++){
                if(this->tab[i+1]<this->tab[i]){
                    float temp = this->tab[i+1];
                    this->tab[i+1]=this->tab[i];
                    this->tab[i]= temp;
                }
            }
        }
    }
    else{
        // max ---> min :
        for(int count=0;count<this->length;count++){
            for(int i=0;i<this->length;i++){
                if(this->tab[i+1]>this->tab[i]){
                    float temp = this->tab[i+1];
                    this->tab[i+1]=this->tab[i];
                    this->tab[i]= temp;
                }
            }
        }
    }
    return;
}

Liste Liste::extract(int in_start, int in_end){
    if(in_start < this->length && in_end <= this->length && in_start<in_end){
        // create a new liste to output :
        int diff = in_end -in_start;
        Liste result = Liste(diff,0.0);
        // update value of liste result:
        for(int i=0;i<diff;i++){
            result.set(this->tab[in_start+i],i);     
        }
        return result;
    }
}

float* Liste::get_tab(){
    return this->tab;
}

void Liste::extend(float* temp){
    int len = sizeof(temp)-1;
    // update len : 
    this->length += len;
    // realloc : 
    this->tab = (float*)realloc(this->tab,this->length*sizeof(float));
    // add item in the end of liste: 
    int start = this->length-len;
    for(int i=0;i<len;i++){
        this->set(temp[i],start+i);
    }
    return;
}

int Liste::in(float item){
    int reponse = 0;
    for(int i=0;i<this->length;i++){
        if(this->tab[i]==item){
            reponse=1;
        }
    }
    return reponse;
}

int Liste::occur(float item){
    int count = 0;
    for(int i=0;i<this->length;i++){
        if(this->tab[i]==item){
            count++;
        }
    }
    return count;
}