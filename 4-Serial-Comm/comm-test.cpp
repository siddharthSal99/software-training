#include <iostream>
#include <boost/asio.hpp>

using namespace std;
using namespace boost::asio;

int main(int argc, char**args) {
  if(argc < 2) {
    cerr << "Usage: 4-comm-test device-path" << endl;
    return EXIT_FAILURE;
  }

  /*
   * Initialize port
   */
  io_service io;
  serial_port port(io);

  try {
    port.open(args[1]);
  } catch(...) {
    cerr << "Could not find device: " << args[1] << endl;
    return EXIT_FAILURE;
  }

  if(!port.is_open()) {
    cerr << "Could not open serial port " << args[1] << endl;
  }

  try {
    port.set_option(serial_port_base::baud_rate(9600));
    port.set_option(serial_port_base::parity(serial_port_base::parity::none));
    port.set_option(serial_port_base::stop_bits(serial_port_base::stop_bits::one));
  } catch(...) {
    cerr << "Could not set options on serial port " << args[1] << endl;
    return EXIT_FAILURE;
  }

  /*
   * Wait for enter key
   */
  cout << "Press enter when arduino light is on." << endl;
  cin.ignore(1000, '\n');
  cin.get();

  /*
   * Send stop command
   */
  string cmd = "stop";
  write(port, buffer(cmd.c_str(), cmd.length()));

  /*
   * Wait for response
   */
  auto bytes = new char[10];
  auto bytes_read = 0;
  while(bytes_read < 10) {
    try {
      read(port, buffer(bytes + bytes_read, 1));
      bytes_read++;
    } catch(...) {
      cerr << "Error reading serial port." << endl;
      return EXIT_FAILURE;
    }
  }

  cout << "Got response: " << bytes << endl;

  return EXIT_SUCCESS;
}