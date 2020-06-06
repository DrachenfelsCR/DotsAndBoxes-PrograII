#pragma once
template <class T>
class iterador {
private:
	virtual bool isDone() = 0;
	virtual void next() = 0;
	virtual T* currentItem() = 0;
	virtual void first() = 0;
};
