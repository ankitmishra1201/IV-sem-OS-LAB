#!/bin/bash


sed -i -e 's/^ex:/Example:/' *.txt       #Replace the ex: in beginning of lines
sed -i -e 's/\. ex:/\. Example:/' *.txt  #Replace the ex: occuring after . 
