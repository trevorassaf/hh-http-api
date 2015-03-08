<?hh

require_once(__DIR__ . '/../../vendor/autoload.php');

/**
 * AutoHttpParamsBuilder
 * - Derives HttpParams instance from POST/GET magic variables.
 */
final class AutoHttpParamsBuilder implements Builder<HttpParams> {
  public function build(): HttpParams {
    return new HttpParams($_POST, $_GET);
  }
}
