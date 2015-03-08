<?hh // strict

final class HttpApiException extends Exception {

  public static function dualOutput(): HttpApiException {
    return new HttpApiException(HttpApiErrorType::DUAL_OUTPUT); 
  }

  public static function missingPayloadKey(): HttpApiException {
    return new HttpApiException(
        HttpApiErrorType::MALFORMED_PARAMS,
        "POST params missing top-level " . OpHttpApi::PAYLOAD_KEY. " key"
    );
  }
  
  public static function badPostParamCount(): HttpApiException {
    return new HttpApiException(
      HttpApiErrorType::MALFORMED_PARAMS,
      "POST params should only contain one top-level param with key: " . OpHttpApi::PAYLOAD_KEY
    );
  }

  public static function unregisteredOp(HttpApiOp $op): HttpApiException {
    return new HttpApiException(
      HttpApiErrorType::INVALID_PARAMS,
      "Http api operation, " . $op . ", is not registered with this api."
    );
  }
  
  public static function invalidJson(string $json): HttpApiException {
    return new HttpApiException(
      HttpApiErrorType::MALFORMED_PARAMS,
      OpHttpApi::PAYLOAD_KEY . " param is invalid json: " . $json
    );
  }

  public function __construct(
    private HttpApiErrorType $errorType,
    string $error_str=''
  ) {
    parent::__construct($error_str);
  }

  public function getErrorType(): HttpApiErrorType {
    return $this->errorType;
  }
}
