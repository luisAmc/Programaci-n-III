template <class min>
min minimo (min arg1, min arg2) {
	min valor = arg1;

	if (arg1 > arg2)
		valor = arg2;

	return valor;
}