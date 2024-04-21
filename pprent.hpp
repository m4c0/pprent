#ifndef PPRENT_HPP
struct dirent;
struct DIR;

namespace pprent {
class iter {
  DIR *m_dir{};
  dirent *m_ent{};
  friend class list;

  explicit iter(DIR *dr);
  explicit constexpr iter() = default;

public:
  bool operator!=(const iter &o) const;

  iter &operator++();
  const char *operator*() const;
};

class list {
  DIR *m_dir;

public:
  explicit list(const char *dir);
  ~list();

  iter begin();
  iter end();
};
} // namespace pprent

#ifdef PPRENT_IMPLEMENTATION
#define MINIRENT_IMPLEMENTATION
#include "../minirent/minirent.h"

namespace pprent {
list::list(const char *dir) : m_dir{opendir(dir)} {}
list::~list() {
  if (m_dir)
    closedir(m_dir);
}
iter list::begin() { return m_dir ? iter{m_dir} : iter{}; }
iter list::end() { return iter{}; }

iter::iter(DIR *dr) : m_dir{dr}, m_ent{readdir(m_dir)} {}
bool iter::operator!=(const iter &o) const {
  // pointer comparison suffices for "normal" usage
  return m_dir != o.m_dir || m_ent != o.m_ent;
}
iter &iter::operator++() {
  if (m_dir)
    m_ent = readdir(m_dir);
  return *this;
}
const char *iter::operator*() const { return m_ent->d_name; }
} // namespace pprent

#endif // PPRENT_IMPLEMENTATION
#endif // PPRENT_HPP
