int readBytes(_Network* network, int* data_array, size_t data_array_length)
{
  ENTRY_POINT;
  UNUSED(network);
  UNUSED(data_array);
  debugPrint(INFO, __DEBUG__ || __RELEASE__, "Reading %d byte(s)", data_array_length);
  EXIT_POINT_WITH_RETURN(TRUE);
}

int writeBytes(_Network* network, int* data_array, size_t data_array_length)
{
  ENTRY_POINT;
  UNUSED(network);
  UNUSED(data_array);
  debugPrint(INFO, __DEBUG__ || __RELEASE__, "Writing %d byte(s)", data_array_length);
  EXIT_POINT_WITH_RETURN(TRUE);
}

int populateNetworkHandle(Network* network)
{
  ENTRY_POINT;
  // TODO: add handle instance
  network->handle.readBytes = readBytes;
  network->handle.writeBytes = writeBytes;
  EXIT_POINT_WITH_RETURN(TRUE);
}

int populateNetwork(Network* network)
{
    ENTRY_POINT;
    if (!populateNetworkHandle(network))
    {
      network->status = BROKEN;
      EXIT_POINT_WITH_RETURN(FALSE);
    }
    network->status = READY;
    EXIT_POINT_WITH_RETURN(TRUE);
}
