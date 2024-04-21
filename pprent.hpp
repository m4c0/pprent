#ifndef PPRENT_HPP
struct dirent;
struct DIR;

namespace pprent {
class iter {
  dirent *m_dir;
  friend class list;

  explicit iter(struct dirent *d);

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
#endif // PPRENT_HPP
