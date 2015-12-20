void writeInFile(int array[], int arraySize, char* file){
	FILE* f = fopen(file, "a+");
	int i, j;
	
	for(i = 0; i < arraySize; i++){
		for(j = 0; j < 4; j++){
			fprintf(f, "_");
		}
	}
	
	fprintf(f, "\n");
	fprintf(f, "|");
	
	//fprintf(f, "\n");
	for(i = 0; i < arraySize; i++){
		fprintf(f, " %i |", array[i]);
	}

	fprintf(f, "\n");

	fclose(f);
}