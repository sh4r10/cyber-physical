#ifndef FILEIO_HPP
#define FILEIO_HPP

void write_header_row(const std::string& filename);
int read_file(const std::string& filename);
void write_file(const std::string& filename, const std::string& previous_commit, const std::string& current_commit, const std::string& data);

#endif //FILEIO_HPP
