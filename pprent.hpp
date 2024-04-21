#ifndef PPRENT_HPP
struct dirent;
struct DIR;

namespace pprent {
class iter {
  DIR *m_dir;
  dirent *m_ent;
  friend class list;

  explicit iter(DIR *dr);
  explicit iter();

public:
  bool operator!=(const iter &) const;
  iter operator++();
  const char *operator*();
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

} // namespace pprent

#endif // PPRENT_IMPLEMENTATION
#endif // PPRENT_HPP
