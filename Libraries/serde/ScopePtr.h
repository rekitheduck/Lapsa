#pragma once

template<class T>
class ScopePtr {
 public:
  constexpr ScopePtr() {}
  ScopePtr(T* pointer) { m_pointer = pointer; }
  ScopePtr(const ScopePtr&) = delete;

  ~ScopePtr() {
    if (m_pointer != nullptr) {
      delete m_pointer;
    }
  }

  T* get() { return m_pointer; }

  T* release() {
    auto temp_ptr = m_pointer;
    m_pointer = nullptr;

    return temp_ptr;
  }

 private:
  T* m_pointer{nullptr};
};

template<class T, class... Args>
constexpr ScopePtr<T> createScope(Args&&... args) {
  return ScopePtr<T>(new T(std::forward<Args>(args)...));
}
