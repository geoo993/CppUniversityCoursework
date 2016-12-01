
template <typename T>
int cityt<T>::has_copy_me = true;

template <typename T>
cityt<T> *cityt<T>::copy_me() const {
  cityt<T>::has_copy_me = false;
  return new cityt<T>(*this);
}
