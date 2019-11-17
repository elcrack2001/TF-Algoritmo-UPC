template <class T>
class ArbolAVL
{
private:
	Node<T>* raiz;//raiz del arbol
	void(*procesar)(T);//puntero a funcion
	//-----------------------------------
	void _restaurarAlturas(Node<T> *& Parent, Node<T> *& LC, Node<T> *& RC)
	{
		if (LC == nullptr && RC == nullptr)
		{
			Parent->height = 1;
			return;
		}
		else
		{
			if (LC != NULL) {
				_restaurarAlturas(LC, LC->Lchild, LC->Rchild);
			}
			if (RC != NULL) {
				_restaurarAlturas(RC, RC->Lchild, RC->Rchild);
			}
			int HLC = _altura(LC);
			int HRC = _altura(RC);
			Parent->height = 1 + _max(HLC, HRC);
		}
	}
	//-----------------------------------
	int _max(int a, int b)
	{
		return (a > b) ? a : b;
	}
	//-----------------------------------
	int _altura(Node<T>*& nodo)
	{
		if (nodo == nullptr)
			return 0;
		return nodo->height;
	}
	//-----------------------------------
	void _insertar(Node<T>*& nodo, T e)
	{
		if (nodo == nullptr)
		{
			nodo = new Node<T>();
			nodo->key = e;
		}
		else if (e >= nodo->key)
			_insertar(nodo->Rchild, e);
		else if (e < nodo->key)
			_insertar(nodo->Lchild, e);

		//=========================================================================================
		int HI = _altura(nodo->Lchild);
		int HD = _altura(nodo->Rchild);
		int DH = HD - HI;
		int ExistCLL, ExistCLR, HNL, HNR;
		bool altura_restaurada = false;
		//CASOS DEL RESULTADO DE LA DIFERENCIA DE ALTURAS EN LOS SUB-ARBOLES DEL NODO ANALIZADO
		switch (DH)
		{
		case -2://DESEQUILIBRIO POR 2 NIVELES EN EL SUB-ARBOL IZQUIERDO
			ExistCLL = _altura(nodo->Lchild->Lchild);//caso left left
			ExistCLR = _altura(nodo->Lchild->Rchild);//caso left right
			if (ExistCLL > ExistCLR) {
				Rotation_R(nodo, nodo->Lchild, nodo);
			}
			if (ExistCLL == ExistCLR) {
				Rotation_R(nodo, nodo->Lchild, nodo);
			}
			if (ExistCLR > ExistCLL)
			{
				Rotation_L(nodo->Lchild, nodo->Lchild->Rchild, nodo->Lchild);
				Rotation_R(nodo, nodo->Lchild, nodo);
			}
			_restaurarAlturas(raiz, raiz->Lchild, raiz->Rchild);
			altura_restaurada = true;
			break;
		case 2://DESEQUILIBRIO POR 2 NIVELES EN EL SUB-ARBOL DERECHO
			HNL = _altura(nodo->Rchild->Lchild);//caso right left (CRL)
			HNR = _altura(nodo->Rchild->Rchild);//caso right right (CRR)
			if (HNR > HNL) {
				Rotation_L(nodo, nodo->Rchild, nodo);
			} // if HNR > HNL
			if (HNR == HNL) {
				Rotation_L(nodo, nodo->Rchild, nodo);
			}
			if (HNL > HNR)
			{
				Rotation_R(nodo->Rchild, nodo->Rchild->Lchild, nodo->Rchild);
				Rotation_L(nodo, nodo->Rchild, nodo);
			}
			_restaurarAlturas(raiz, raiz->Lchild, raiz->Rchild);
			altura_restaurada = true;
			break;
		}
		//=========================================================================================
		if (altura_restaurada == false) {
			nodo->height = 1 + this->_max(HI, HD);
		}
	}
	//-----------------------------------
	void Rotation_L(Node<T>* nodo_a, Node<T>*& nodo_b, Node<T>*& nodo_p)
	{
		nodo_p = nodo_b;
		nodo_a->Rchild = nodo_b->Lchild;
		nodo_p->Lchild = nodo_a;
	}
	//-----------------------------------
	void Rotation_R(Node<T>* nodo_a, Node<T>*& nodo_b, Node<T>*& nodo_p)
	{
		nodo_p = nodo_b;
		nodo_a->Lchild = nodo_b->Rchild;
		nodo_p->Rchild = nodo_a;
	}
	//-----------------------------------
	void _MenorAMayor(Node<T>* nodo)
	{
		if (nodo == nullptr)
			return;
		_MenorAMayor(nodo->Lchild);
		procesar(nodo->key);
		_MenorAMayor(nodo->Rchild);
	}
	//-----------------------------------
public:
	ArbolAVL(void(*pf)(T))
	{
		this->procesar = pf;
		raiz = nullptr;
	}
	//-----------------------------------
	void Insertar(T e) { _insertar(raiz, e); }
	void Eliminar(T e) { _eliminar(raiz, e); }
	void MenorAMayor() { _MenorAMayor(raiz); }
	//-----------------------------------
};