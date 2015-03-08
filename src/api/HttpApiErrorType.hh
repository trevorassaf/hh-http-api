<?hh // strict

enum HttpApiErrorType: int {
  /**
   * Api call produced competing textual outputs.
   */
  DUAL_OUTPUT = 0x00;

  /**
   * Api received malformed params (invalid structure)
   */
  MALFORMED_PARAMS = 0x01;

  /**
   * Api received invalid params (invalid content)
   */
  INVALID_PARAMS = 0x02;
}
