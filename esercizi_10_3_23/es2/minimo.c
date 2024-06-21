int Minimo(const int* v, int v_size) {
	int minimo;
	if (v_size == 1) {
		minimo=v[v_size-1];
	}
	else {
		minimo=Minimo(v, v_size-1);
	}
	minimo = min(v, v_size,minimo);
	return minimo;
}

int min(const int* v, int v_size,int minimo) {

	if (v[v_size - 1] < minimo) {
		return minimo = v[v_size - 1];
	}
	else
		return minimo;
}
